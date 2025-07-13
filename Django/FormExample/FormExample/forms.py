#user defined
from django import forms




class userForm(forms.Form):
    input1 = forms.CharField(label="Username", required=True, widget=forms.TextInput(attrs={'class': 'form-control'}))
    input2 = forms.CharField(label="Password", required=False, widget=forms.PasswordInput(attrs={'class': 'form-control'}))