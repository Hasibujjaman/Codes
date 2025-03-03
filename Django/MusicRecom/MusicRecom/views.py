
from django.shortcuts import render,redirect
from django.contrib.auth.models import User

import pickle
import spotipy
from spotipy.oauth2 import SpotifyClientCredentials
from RegistrationApp.models import Registration #importing the model class from models.py
from django.core.mail import send_mail # for sending email
from django.core.mail import EmailMultiAlternatives # for sending email with html content




CLIENT_ID = "b988fcb3b95a4f91928a167878b2902b"
CLIENT_SECRET = "c4b25b90c40b4599a25b2711957e80e3"

# Initialize the Spotify client
client_credentials_manager = SpotifyClientCredentials(client_id=CLIENT_ID, client_secret=CLIENT_SECRET)
sp = spotipy.Spotify(client_credentials_manager=client_credentials_manager)



def get_albumCover_albumName_popularity_preview(song_name, artist_name):
    search_query = f"track:{song_name} artist:{artist_name}"
    results = sp.search(q=search_query, type="track", limit=2) # track -> items(list) -> album -> images(list) -> url

    if results and results["tracks"]["items"]:
        trackItem = results["tracks"]["items"][0]
        # print(trackItem)

        album_cover_url = trackItem["album"]["images"][0]["url"]
        album_name = trackItem["album"]["name"]
        popularity = trackItem["popularity"]
        preview_url = trackItem["preview_url"]
        spotify_url = trackItem["external_urls"]["spotify"]

        #print(spotify_url)
        return [album_cover_url, album_name, popularity, preview_url, spotify_url]
    else:
        return ["https://i.postimg.cc/0QNxYz4V/social.png", "", 0, "", ""]



def recommend(song):
    index = dataFrame[dataFrame['song'] == song].index[0]
    distances = sorted(list(enumerate(similarity[index])), reverse=True, key=lambda x: x[1]) # sorted list of 2-tuples (index, similarity)
    recommended_music_names = []
    recommended_music_artists = []
    recommended_music_posters = []
    recommended_music_album_names = []
    recommended_music_popularities = []
    recommended_music_preview_urls = []
    recommended_music_spotify_urls = []

    for tupple in distances[0:12]:

        artist = dataFrame.iloc[tupple[0]].artist

        recommended_music_names.append(dataFrame.iloc[tupple[0]].song)
        recommended_music_artists.append(artist)

        albumCover_albumName_popularity_preview = get_albumCover_albumName_popularity_preview(dataFrame.iloc[tupple[0]].song, artist)
        recommended_music_posters.append(albumCover_albumName_popularity_preview[0])
        recommended_music_album_names.append(albumCover_albumName_popularity_preview[1])
        recommended_music_popularities.append(albumCover_albumName_popularity_preview[2])
        recommended_music_preview_urls.append(albumCover_albumName_popularity_preview[3])
        recommended_music_spotify_urls.append(albumCover_albumName_popularity_preview[4])

    return recommended_music_names, recommended_music_artists, recommended_music_posters, recommended_music_album_names, recommended_music_popularities, recommended_music_preview_urls, recommended_music_spotify_urls






dataFrame = pickle.load(open('MusicRecom/df.pkl','rb')) # load the dataframe
similarity = pickle.load(open('MusicRecom/similarity.pkl','rb')) # load the similarity matrix


def homePage(request):
    print(f"User ID: {request.session.get('user_name')}")

    music_list = dataFrame['song'].values # get the list of all the songs

    recommended_music_names = []
    recommended_music_artists = []
    recommended_music_posters = []
    recommended_music_album_names = []
    recommended_music_popularities = []
    recommended_music_preview_urls = []
    recommended_music_spotify_urls = []

    recommended_music = zip(recommended_music_names, recommended_music_artists, recommended_music_posters, recommended_music_album_names, recommended_music_popularities, recommended_music_preview_urls, recommended_music_spotify_urls)

    if request.method == "POST":
        selected_music = request.POST.get("selected_song")  # Get the selected song from the form
        action = request.POST.get('action')

        if selected_music:
            # print(selected_music)
            recommended_music_names, recommended_music_artists, recommended_music_posters, recommended_music_album_names, recommended_music_popularities, recommended_music_preview_urls, recommended_music_spotify_urls = recommend(selected_music)
            print(recommended_music_preview_urls)

            if action == "submit":
                recommended_music = zip(recommended_music_names[:6], recommended_music_artists[:6], recommended_music_posters[:6], recommended_music_album_names[:6], recommended_music_popularities[:6], recommended_music_preview_urls[:6], recommended_music_spotify_urls[:6])
            elif action == "refresh":
                recommended_music = zip(recommended_music_names[6:], recommended_music_artists[6:], recommended_music_posters[6:], recommended_music_album_names[6:], recommended_music_popularities[6:], recommended_music_preview_urls[6:], recommended_music_spotify_urls[6:])

            return render(request, "home.html", {
                'recommended_music': recommended_music,
                'music_list': music_list,
                'selected_music': selected_music  # Optional: for showing the selected music again in the template
            })

    return render(request, "home.html", {'recommended_music': recommended_music, 'music_list': music_list})




# def loginPage(request):
#     uname = ""
#     password = ""
#     output = ""
#     try:
#         if request.method == "POST":
#             uname = request.POST["uname"]
#             password = request.POST.get("pass")

#             registrationData = Registration.objects.filter(reg_name=uname)
#             if registrationData.exists():
#                 signatureFromDB = registrationData[0].reg_name + registrationData[0].reg_password
#                 signatureFromUserInput = uname + password
#                 if signatureFromDB == signatureFromUserInput:
#                     # Store user data in session
#                     # meek start
#                     request.session['user_id'] = registrationData[0].id
#                     request.session['user_name'] = registrationData[0].reg_name
#                     # meek end
#                     print("logged in")
#                     return redirect("/")
#                 else:
#                     print("incorrect password")
#                     output = "Incorrect credentials"
#             else:
#                 output = "User not found"

#     except:
#         print("exception occured")
#         pass

#     return render(request, "loginForm.html", {'uname':uname, 'password':password, 'output': output})

def loginPage(request):
    uname = ""
    password = ""
    error = ""  # Variable to hold error messages
    try:
        if request.method == "POST":
            uname = request.POST["uname"]
            password = request.POST.get("pass")

            registrationData = Registration.objects.filter(reg_name=uname)
            if registrationData.exists():
                signatureFromDB = registrationData[0].reg_name + registrationData[0].reg_password
                signatureFromUserInput = uname + password
                if signatureFromDB == signatureFromUserInput:
                    # Store user data in session
                    request.session['user_id'] = registrationData[0].id
                    request.session['user_name'] = registrationData[0].reg_name
                    print("logged in")
                    return redirect("/")
                else:
                    print("incorrect password")
                    error = "Incorrect password. Please try again."
            else:
                error = "User not found. Please check your username."
    except Exception as e:
        print(f"Exception occurred: {e}")
        error = "An error occurred while processing your request. Please try again."

    return render(request, "loginForm.html", {'uname': uname, 'password': password, 'error': error})


# meek start
def logoutUser(request):
    request.session.flush()
    return redirect('/')
# meek end


def registrationPage(request):
    verdict = 0 # 0 means success or first loading of the page, 1 means username already exists, 2 means email already exists

    if request.method == "POST":
        name = request.POST.get("name")
        email = request.POST.get("email")
        password = request.POST.get("password")

        #check if the user already exists
        user = Registration.objects.filter(reg_name=name)
        if user.exists():
            return render(request,"registration.html",{'verdict':1})
        user = Registration.objects.filter(reg_email=email)
        if user.exists():
            return render(request,"registration.html",{'verdict':2})

        ## creates Registration type object for storing in the Registration table of the database
        reg = Registration(reg_name=name,reg_email=email,reg_password=password)
        reg.save() # save the object in the database
        return redirect("/")

    return render(request,"registration.html",{'verdict':verdict})



def contactPage(request):
    if request.method == "POST":
        name = request.POST.get("name")
        email = request.POST.get("email")
        subject = request.POST.get("subject")
        message = request.POST.get("message")


        # send_mail(
        #     subject,
        #     message,
        #     'settings.EMAIL_HOST_USER',
        #     ['emonahamed789@gmail.com'],
        #     fail_silently=False,
        # )
        html_content_subject = "Django project Email"
        html_content_message = "<b> From:</b>"+name+"<br><b>Email:</b>"+email+"<br><b>Subject:</b>"+subject+"<br><br><b>Message:</b><i>"+message+"</b>"
        send_from = 'settings.EMAIL_HOST_USER'
        send_to = ['emonahamed789@gmail.com','example@gmail.com']
        mail = EmailMultiAlternatives(html_content_subject, html_content_message,send_from,send_to)
        mail.content_subtype = 'html'
        mail.send()




    return render(request,"contactPage.html")