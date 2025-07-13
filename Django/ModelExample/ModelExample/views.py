from django.shortcuts import render,redirect
from ServicesApp.models import Service  #importing the model class from models.py for database operation
from RegistrationApp.models import Registration #importing the model class from models.py
from django.core.mail import send_mail # for sending email
from django.core.mail import EmailMultiAlternatives # for sending email with html content

def homePage(request):
    ##  get service data from database
    servicesData = Service.objects.all() # get all data from the ServiceApp's service table which is in database
    # servicesData = Service.objects.all().order_by('service_title') # use '-service_title' to get the data in descending order
    # servicesData = Service.objects.all().order_by('service_title')[0:2] # get the first two data (in ascending order) from the database
    marqueeData = servicesData
    
    ## search functionality
    if request.method == "GET":
        search = request.GET.get("search")
        if search != None:
            servicesData = Service.objects.filter(service_title__icontains=search) # for partial match
            # servicesData = Service.objects.filter(service_title=search) # for exact match)

    return render(request,"index.html",{'servicesData':servicesData, 'marqueeData':marqueeData})



# For POST method with use of action attribute in form
def loginPage(request):
    uname = ""
    password = ""
    output = ""
    try:
        if request.method == "POST":
            uname = request.POST["uname"] # POST method is used to get the data from the form 
            password = request.POST.get("pass")
            
            #registrationData = Registration.objects.filter(reg_name=uname,reg_password=password) # get the data from the Registration table of the database
            registrationData = Registration.objects.filter(reg_name=uname)
            if registrationData.exists():
                signatureFromDB =   registrationData[0].reg_name+registrationData[0].reg_password
                signatureFromUserInput = uname+password
                if signatureFromDB == signatureFromUserInput:
                    print("Entered signature is: "+ signatureFromUserInput)
                    print("logged in")
                    return redirect("/")
                else:
                    print("login failed")
                    output = "Incorrect password"
            else:
                output="User not found"

    
        # print(uname) #for debugging
        # print(password) #for debugging
        
    except:
        print("exception occured")
        pass

    return render(request,"loginForm.html",{'uname':uname, 'password':password,'output': output}) 

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



def calculator(request):
    operand1 = 0
    operand2 = 0
    result = ""
    try:
        if request.method == "POST":
            operand1 = eval(request.POST["operand1"])
            operand2 = eval(request.POST.get("operand2"))
            operator = request.POST.get("operator")
            if(operator=="+"):
                result = operand1 + operand2
            elif(operator=="-"):       
                result = operand1 - operand2
            elif(operator=="*"):
                result = operand1 * operand2
            elif(operator=="/"):
                result = operand1 / operand2
        
        
    except Exception as e:
        result = "Invalid operation"
        print(e)
        pass
    print(result)
    return render(request,"calculator.html",{'res':result})



def detailPage(request,slug):
    detail = Service.objects.get(service_slug=slug) # get the row from the Service table of the Database by id attribute
    #detail.service_icon = str(detail.service_icon).replace("static/","") # it is necessary to remove the 'static/' from the image path otherwise static/ will be added twice in the path because {% static .... %} will add 'static/' in the path and we already have it included in the service_icon 
    print(detail.service_icon)

    return render(request,"detailPage.html",{'detail':detail})



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