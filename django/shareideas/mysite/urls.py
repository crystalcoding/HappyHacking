from django.conf.urls.defaults import *
from mysite.views import index, contact,hello, search_form, search
# Uncomment the next two lines to enable the admin:
from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    ('^hello/$', hello),
    (r'^search_form/$', search_form),
    ('^search/$', search),
    (r'^$', index),
    (r'^contact/$', contact),
    (r'^idea/$', 'mysite.board.views.index'),
    (r'^idea/vote/(\d+)', 'mysite.board.views.vote'),
    (r'^idea/post/$', 'mysite.board.views.post'),
    (r'^idea/submit_post/$', 'mysite.board.views.submit_post'),
    (r'^idea/comment/(\d+)', 'mysite.board.views.comment'),
    (r'^idea/submit_comment/(\d+)', 'mysite.board.views.submit_comment'),
    # Example:
    # (r'^mysite/', include('mysite.foo.urls')),

    # Uncomment the admin/doc line below and add 'django.contrib.admindocs' 
    # to INSTALLED_APPS to enable admin documentation:
    # (r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    (r'^admin/', include(admin.site.urls)),
)
