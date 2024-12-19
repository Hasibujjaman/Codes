""" we can create views here which is responsible for handling the request and returning the response to the user. """

from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def function1(request):
    return HttpResponse("This is view function of the FirstApp")

# def homeFirstApp(request):
#     return render(request,"FirstAppHome.html")
""" We can pass data to the template using the render function. The render function takes the request object, the template name, and a dictionary as its arguments. The dictionary contains the data that we want to pass to the template. """
def homeFirstApp(request):
    return render(request,"FirstAppHome.html", {'key1':'Emon', 'key2':'Chowdhury'})
