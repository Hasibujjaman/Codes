#user defined file
from django.urls import path
from .import views

urlpatterns = [
    path('FirstPage/', views.function1),
    path('', views.homeFirstApp, name='homeFirstApp'),
]
