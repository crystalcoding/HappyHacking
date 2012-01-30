# Create your views here.

from django.template import Context, loader
from django.shortcuts import get_object_or_404
from django.http import HttpResponse
from django.shortcuts import render_to_response

from mysite.board.models import Idea, Comment, Invest
from time import strftime


def index(request):
    #note the "negative sign"
    ideas = Idea.objects.all().order_by('-vote') 

    idea_list = []
    for i in ideas:
        entry = []
        entry.append(i)
        comment_count = Comment.objects.filter(idea=i).count()
        entry.append(comment_count)
        idea_list.append(entry)

    t = loader.get_template('idea/index.html')
    c = Context({
            'idea_list':idea_list,
    })
    return HttpResponse(t.render(c))

def vote(request, Idea_id):
    #the_idea = idea.objects.get(pk=idea_id)
    the_idea = get_object_or_404(Idea, pk=Idea_id)
    if the_idea:
        the_idea.vote += 1
        the_idea.save();
        return render_to_response('idea/vote_result.html', {'idea':the_idea});
    else:
        return HttpResponse("not right")

def post(request):
    t = loader.get_template('idea/post.html')
    c = Context()
    return HttpResponse(t.render(c))

def submit_post(request):
    newtitle = ""
    newflag = ""
    newname = ""
    newdescr = ""

    if 'title' in request.POST and request.POST['title']:
        newtitle = request.POST['title']
    if 'descr' in request.POST and request.POST['descr']:
        newdescr = request.POST['descr']
    if 'flag' in request.POST and request.POST['flag']:
        newflag = request.POST['flag']
    if 'name' in request.POST and request.POST['name']:
        newname = request.POST['name']


    #now make sure things are ok before writing to database    
    error = False
    if not newtitle:
        error = True
    else:
        new_idea = Idea(title=newtitle,descr=newdescr,vote=0,view=0,flag=newflag,name=newname, date=strftime("%Y-%m-%d"))
        new_idea.save()

    return render_to_response('idea/submit_result.html', {'error':error});


def comment(request, Idea_id):
    comments = Comment.objects.filter(idea=Idea_id)
    idea = Idea.objects.get(pk=Idea_id)
    return render_to_response('idea/show_comments.html', {'idea':idea, 'comments':comments})
    
def submit_comment(request, Idea_id):
    newname = "(nothing)"
    newtext = "(nothing)"
    if 'name' in request.POST and request.POST['name']:
        newname = request.POST['name']
    if 'user_comment' in request.POST and request.POST['user_comment']:
        newtext = request.POST['user_comment']

    #add code to check if idea exists
    new_comment = Comment(idea=Idea(pk=Idea_id),text=newtext,name=newname,date=strftime("%Y-%m-%d"))

    new_comment.save()

    
    return render_to_response('idea/submit_comment_result.html', {'idea_id':Idea_id})
