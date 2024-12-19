from django.shortcuts import render,redirect



def homePage(request):

    return render(request,"index.html")



# For POST method with use of action attribute in form
def loginPage(request):
    uname = ""
    password = ""
    output = ""
    try:
        if request.method == "POST":
            uname = request.POST["uname"] # POST method is used to get the data from the form 
            password = request.POST.get("pass")
            
            signatureFromDB = "Emon123"  # fetch from database
            signatureFromUserInput = uname+password
            if signatureFromDB == signatureFromUserInput:
                print("Entered signature is: "+ signatureFromUserInput)
                print("logged in")
                return redirect("/")
            else:
                print("login failed")
                output = "Login failed"

    
        # print(uname) #for debugging
        # print(password) #for debugging
        
    except:
        print("exception occured")
        pass

    return render(request,"loginForm.html",{'uname':uname, 'password':password,'output': output}) 



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







def redirectPage(request):
    if request.method == "GET":
        uname = request.GET.get("uname")
        password = request.GET.get("pass")
        
    if request.method == "POST":
        uname = request.POST.get("uname")
        password = request.POST.get("pass")
        
    
    return render(request,"redirect.html",{'output':uname+password})