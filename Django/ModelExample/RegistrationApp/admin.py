from django.contrib import admin
from RegistrationApp.models import Registration ## import your model class here which you have defined in the models.py

# Register your models here.
class RegistrationAdmin(admin.ModelAdmin):
    list_display = ['reg_name','reg_email','reg_password'] ## display these fields in the admin panel

#register your model class here
admin.site.register(Registration,RegistrationAdmin)