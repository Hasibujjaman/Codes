#user defined file
from django.http import HttpResponse
from django.shortcuts import render # for rendering html files

"""
Before you add your own routes Django will serve the default home page at the '/' url. 
After you add your own route config, django no longer serves up its default sample home page.
So if you want to use that use need to define that function here in order to use it again
"""

#
# def homePage(request):

#     return HttpResponse("Home Page")
def homePage(request):

    return render(request,"HomePage.html")


def aboutUs(request):
    return HttpResponse("Welcome to Web Dev")


def courses(request):
    return HttpResponse("All courses are available here")


def courseX(request,course_id): #the second parameter is for dynamic url
    return HttpResponse("Details of course no "+str(course_id))



