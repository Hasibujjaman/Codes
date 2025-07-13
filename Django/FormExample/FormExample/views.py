from django.shortcuts import render,redirect
from .forms import userForm



def homePage(request):

    return render(request,"indexV2.html")


# For GET method (which is set as default) example
def loginPageV1(request):
    usrname = ""
    password = ""
    fn = userForm()
    try:  
        usrname = request.GET["input1"] # GET method is used to get the data from the URL which 
        password = request.GET.get("input2")
        print(usrname)
        print(password)
    except:
        print("exception occured")
        pass
    
    return render(request,"loginForm.html",{'val': usrname+password, 'form':fn})


