"""We configure how the app is going to behave here"""

from django.apps import AppConfig


class FirstappConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'FirstApp'
