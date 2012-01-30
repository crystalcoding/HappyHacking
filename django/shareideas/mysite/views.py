from django.http import HttpResponse
from django.shortcuts import render_to_response

def index(request):
    return render_to_response('index.html')

def contact(request):
    return render_to_response('contact.html')

def hello(request):
    return HttpResponse("Hello world")

def search_form(request):
    return render_to_response('search_form.html')

def search(request):
    if 'q' in request.GET:
        message = 'you searched for: %r' % request.GET['q']
    else:
        message = 'you submitted an empty form.'

    return HttpResponse(message)
