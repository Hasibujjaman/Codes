from django.db import models
from django.contrib.auth.models import User
# Create your models here.

class Registration(models.Model):
    reg_name = models.CharField(max_length=100,unique=True)
    user = models.OneToOneField(User, on_delete=models.CASCADE, null=True)
    reg_email = models.EmailField()
    reg_password = models.CharField(max_length=50)

    def __str__(self):
        return self.reg_name
