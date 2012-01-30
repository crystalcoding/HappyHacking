from django.db import models

# Create your models here.

class Idea(models.Model):
    title = models.CharField(max_length=100)
    descr = models.CharField(max_length=200)
    vote  = models.IntegerField()
    view  = models.IntegerField()
    flag  = models.CharField(max_length=10)
    name  = models.CharField(max_length=10)
    date  = models.CharField(max_length=10)

class Comment(models.Model):
    idea = models.ForeignKey(Idea)
    text = models.CharField(max_length=200)
    name  = models.CharField(max_length=10)
    date  = models.CharField(max_length=10)

class Invest(models.Model):
    idea = models.ForeignKey(Idea)
    money = models.IntegerField()
    name  = models.CharField(max_length=10)
    date  = models.DateTimeField('date published')
    
