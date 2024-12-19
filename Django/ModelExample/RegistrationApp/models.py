from django.db import models
# Create your models here.

class Registration(models.Model):
    reg_name = models.CharField(max_length=100,unique=True)
    reg_email = models.EmailField()
    reg_password = models.CharField(max_length=50)

    def __str__(self):
        return self.reg_name
