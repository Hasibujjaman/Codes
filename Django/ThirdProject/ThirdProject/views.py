from django.shortcuts import render,redirect



def homePage(request):

    return render(request,"indexV2.html")


def featurePage(request):

    return render(request,"features.html")

def downloadPage(request):

    return render(request,"download.html")


# For GET method (which is set as default) example
def loginPagV1(request):
    usrname = ""
    password = ""
    try:  
        usrname = request.GET["uname"] # GET method is used to get the data from the URL which 
        password = request.GET.get("pass")
        print(usrname)
        print(password)
    except:
        print("exception occured")
        pass
    
    return render(request,"loginForm.html",{'val': usrname+password})


# For POST method example v1
def loginPageV2(request):
    uname = ""
    password = ""
    try:
        if request.method == "POST":
            uname = request.POST["uname"] # POST method is used to get the data from the form 
            password = request.POST.get("pass")
            
            url = "/redirect/?output={}".format(uname+password) # for sending data to a redirected page through URL 
            return redirect(url)
    
        # print(uname) #for debugging
        # print(password) #for debugging
        
        
    except:
        print("exception occured")
        pass

    return render(request,"loginFormV2.html",{'uname':uname, 'password':password,'output': uname+password})

# For POST method with use of action attribute in form
def loginPageV3(request):
    uname = ""
    password = ""
    try:
        if request.method == "POST":
            uname = request.POST["uname"] # POST method is used to get the data from the form 
            password = request.POST.get("pass")
    
        # print(uname) #for debugging
        # print(password) #for debugging
        
        
    except:
        print("exception occured")
        pass

    return render(request,"loginFormV3.html",{'uname':uname, 'password':password,'output': uname+password})







def redirectPage(request):
    if request.method == "GET":
        uname = request.GET.get("uname")
        password = request.GET.get("pass")
        
    if request.method == "POST":
        uname = request.POST.get("uname")
        password = request.POST.get("pass")
        
    
    return render(request,"redirect.html",{'output':uname+password})