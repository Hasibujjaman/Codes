"""
URL configuration for SecondProject project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include
from SecondProject import views
import debug_toolbar # for using the debug toolbar


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.homePage), # This is the url configuration for the home page (root url)
    path('FirstApp/', include('FirstApp.urls')), # This is the url configuration for the FirstApp
    path('__debug__/', include('debug_toolbar.urls')), # This is the url configuration for the debug toolbar
]
