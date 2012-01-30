from mysite.board.models import Idea, Comment, Invest
from django.contrib import admin

class ideaAdmin(admin.ModelAdmin):
    list_display = ('title', 'descr')

class commentAdmin(admin.ModelAdmin):
    list_display = ('text', 'name')

class investAdmin(admin.ModelAdmin):
    list_display = ('money', 'name')

#this way we have our own to-string method
admin.site.register(Idea, ideaAdmin)
admin.site.register(Comment, commentAdmin)
admin.site.register(Invest, investAdmin)
