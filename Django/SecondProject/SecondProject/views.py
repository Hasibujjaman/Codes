#user defined file

from django.http import HttpResponse
from django.shortcuts import render # for rendering html files




# def homePage(request):
    
#     return HttpResponse("Home Page")

"""Example of passing data from Django view to template"""
def homePage(request):
    data = {
        'name': 'Emon',
        'age': 25,
        'country': 'Bangladesh',
        'relatives': ['Father', 'Mother', 'Brother'],
        'contacts' : [{'name': 'Mother', 'phone': '01700000000'}, {'name': 'Fater', 'phone': '01700000001'}, {'name': 'Brother', 'phone': '01700000002'}], # a list of dictionaries
        'numbers' : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    }
    
    return render(request, 'home.html', data)
