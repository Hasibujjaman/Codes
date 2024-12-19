from django.db import models
from autoslug import AutoSlugField  # pip install django-autoslug for this package


# Create your models here.

class Service(models.Model):
    service_icon = models.ImageField(upload_to='ServicesApp/uploads/icons')
    service_title = models.CharField(max_length=100)
    service_description = models.TextField()
    service_file = models.FileField(upload_to='ServicesApp/uploads/files',null=True,default=None)

    service_slug = AutoSlugField(populate_from='service_title', unique=True, null=True, default=None) # this will create a slug field for the service_title field
   

    """Without the __str__ method, Django would show a less informative default representation, 
    such as "Service object (1)". With the __str__ method defined, the admin site will instead display
    the string returned by __str__, making it easier to identify specific instances of the model."""
    def __str__(self):
        return self.service_title



