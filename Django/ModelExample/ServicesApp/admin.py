from django.contrib import admin
from ServicesApp.models import Service ## import your model class here which you have defined in the models.py

# Register your models here.
class ServiceAdmin(admin.ModelAdmin):
    list_display = ['service_title','service_icon','service_file','service_description'] ## display these fields in the admin panel


## register your model class here
admin.site.register(Service,ServiceAdmin) 