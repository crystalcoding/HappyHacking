require 'open-uri'
require 'rexml/document'

#prepare for YouTube API
url_1 = 'http://gdata.youtube.com/feeds/api/videos?author=chunglo&vq=zelda&max-results=50&orderby=published&start-index=101'
url_2 = 'http://gdata.youtube.com/feeds/api/videos?author=chunglo&vq=zelda&max-results=50&orderby=published&start-index=51'
url_3 = 'http://gdata.youtube.com/feeds/api/videos?author=chunglo&vq=zelda&max-results=50&orderby=published'
tutorial = Array[url_3, url_2, url_1] #URL array for YouTube API
result = Array.new #array to store the results
result_index = 106 #index for results
puts 'Please wait, fetching all Wii Zelda video walkthroug...', '(3~10 sec depends on your network connection)', ''

#start parsing data with XPath
for i in 0..tutorial.length-1 do
    doc = REXML::Document.new open(tutorial[i]).read
    doc.elements.each('//entry//media:group/') do |f|
      result[result_index] = String.new(f.children[0].text) +" => "+ (f.children[7].attribute('url').value)
      result_index -= 1      
    end
    puts 'done fetching a group, fetching more...', ''
end

#write the result to a file
file=File.new("Wii_Zelda.txt","w+")
result.each do |r|
    puts r
    file.puts r
end
puts '','Results saved to Wii_Zelda.txt','Done, enjoy the game!','(press any key to end the program...)'
gets #this is for windows only, so the console will pause itself

