
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background-color: rgb(241, 242, 243);">Lab 2: Recursion</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time datetime="2014-11-05T23:59:59+08:00" class="due_time" style="font-weight: bold;">2014-11-05 23:59 UTC+8</time></span><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/lab2/Demo.tar.gz" class="assignment_ref" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background: rgb(204, 204, 204);">Test Case</a>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Introduction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">The recursive solutions to most of these problems are quite short - typically less than a dozen lines each. That doesn't mean you should put this assignment off until the last minute though - recursive solutions can often be formulated in a few concise, elegant lines but the density and complexity that can be packed into such a small amount of code may surprise you.</p>
</div>
</div>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">City Construction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Remember NOKIA "brick" cells? In this lab, we'll certainly not teach you how to smash a nut with a NOKIA. Instead, we may make you realize how tough a "NOKIA" problem is.</p>
<p style="margin: 8px 0px;">There's once a popular game "Skyscraper" in the ancient Symbian OS, where there are two modes provided to players. One is to build a skyscraper as tall as you can with help from a drunk crane. The more floors you built, the more score you got. The other mode is called "City Construction", where you'll build many houses on a large space. The larger population those houses can hold, the more score you can get.</p>
<p style="margin: 8px 0px;">Now we apply a simplification on this problem:</p>
<p style="margin: 8px 0px;">1.Suppose there's an empty ground divided into M x N blocks, in which can we build one house in each block.</p>
<p style="margin: 8px 0px;">2.There are totally 3 kinds of house you can build: red, green and blue one.</p>
<p style="margin: 8px 0px;">3.However, there are restricts to building the green and blue houses. Green houses can be built in a block if there's at least one red house in the neighborhood; blue houses can be built if there are at least one red and one green house near by.</p>
<p style="margin: 8px 0px;">4.We consider only 4 houses in the nearest north, south, east and west as neighbors of one block.</p>
<p style="margin: 8px 0px;">5.Population that 3 kinds of houses can hold are: Red-1, Green-2, Blue-3.</p>
<p style="margin: 8px 0px;">6.Our goal is to find out a construction plan such that no other plan can hold a larger population.</p>
</div>
</div>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Format of Input and Output</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">This time we won't provide any start code for you, because that may constrain your imagination of programming. We believe you are getting well with C/C++. Thus we allow you to use any data structure you love and write any code you want. Nevertheless, we shall make a little consensus among input and output format in this program.</p>
<p style="margin: 8px 0px;">1.Parameters in main() function</p>
<p style="margin: 8px 0px;">This time you should write your main() function to accept arguments in command line. That means when you run your program in terminal, it should look like this:</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">~$ ./city input.txt output.txt</code></p>
<p style="margin: 8px 0px;">In this command line, "city" is the name of your program, "input.txt" is the name of input data file which contains many test cases, and "output.txt" is the name of the output file where you shall write down your result.</p>
<p style="margin: 8px 0px;">2.Format of input file</p>
<p style="margin: 8px 0px;">First line in this file should be a number "T", the number of test cases. The following T lines should contain 2 numbers "M" and "N" in each which refer to rows and columns of blocks in each test cases.</p>
<p style="margin: 8px 0px;">e.g.</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">3<br>2 1<br>1 2<br>3 3<br></code></p>
<p style="margin: 8px 0px;">3.Format of output file</p>
<p style="margin: 8px 0px;">Output file should contain "T" parts. Each represents the result of one of T test cases(mentioned above). In each part, you should write down the maximum population you found in the first line. And then, you should print a M x N matrix that represents the construction plan.</p>
<p style="margin: 8px 0px;"><b>ATTENTION:</b>In that matrix, you should use 1 for "Red House", 2 for "Green House" and 3 for "Blue House".</p>
<p style="margin: 8px 0px;">e.g.(Suppose "input.txt" is the example above)</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">3<br>1<br>2<br>3<br>1 2<br>19<br>3 1 3<br>2 1 2<br>3 1 3<br></code></p>
</div>
</div>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hints</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">1.Use parameters in main() function</p>
<p style="margin: 8px 0px;">To do this, you should write your main() function as following code does:</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">int main(int argc, char** argv)<br>{<br>&nbsp;&nbsp;printf("%d\n", argc);<br>&nbsp;&nbsp;for (int i = 0; i &lt; argc; i++)<br>&nbsp;&nbsp;{<br>&nbsp;&nbsp;&nbsp;&nbsp;printf("%s\n", argv[i]);<br>&nbsp;&nbsp;}<br>&nbsp;&nbsp;return 0;<br>}<br></code></p>
<p style="margin: 8px 0px;">Play with that code for several times, then you'll find the meaning of those two arguments.</p>
<p style="margin: 8px 0px;">If you want to know more about this usage, you can search through the Internet.</p>
<p style="margin: 8px 0px;">2.File operation</p>
<p style="margin: 8px 0px;">To follow the input/output format mentioned in former part, you should know how to read/write a text file. To do this, you may find these functions useful:</p>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">File operation in std library.</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">#include &lt;stdio.h&gt;<br>//open<br>FILE * fopen(const char * path,const char * mode);<br>//close<br>int fclose(FILE *stream);<br>//input<br>int fscanf(FILE *stream, const char *format, [argument...]);<br>//output<br>int fprintf(FILE *stream, const char *format, [argument...]);<br></code></p>
<p style="margin: 8px 0px;">C++ file stream</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">#include &lt;fstream&gt;<br>//input<br>ifstream input_file;<br>input_file.open("input.txt");<br>input_file&gt;&gt;m&gt;&gt;n;<br>input_file.close();<br>//output<br>ofstream output_file;<br>output_file.open("output.txt");<br>output_file&lt;&lt;m&lt;&lt;n;<br>output_file.close();<br></code></p>
</div>
<p style="margin: 8px 0px;">We recommend you to use the "stdlib" way. Because you may find it a little tricky using C++ fstream.</p>
</div>
</div>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand In</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">In this lab, you should write your code in only one source file named as "&lt;student NO.&gt;.cpp"(e.g. "5130379001.cpp"). And write a "ReadMe" file named "ReadMe.txt" to briefly describe your data structure and the algorithms you use. You can use as many algorithms you like to do this lab. But remember to apply recursive algorithm at least once. If you use other algorithms, please write them into other independent source files(that can be compiled independently to other executables) with another "ReadMe" file to describe them.</p>
<p style="margin: 8px 0px;">You should pack up source file(which applied recursive algorithms) and the corresponding "ReadMe" file to</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/lab2_recursion/<br>Username: azard5, Password:public</code>
<p style="margin: 8px 0px;">And pack up other source files(which applied other algorithms) and corresponding "ReadMe" file to</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/lab2_otherAlgorithms/<br>Username: azard5, Password:public</code>
<p style="margin: 8px 0px;">We may give you additional points for it.</p>
<p style="margin: 8px 0px;">The package name you hand in should be like this: "5130379001.tar.gz"</p>
</div>
</div>
<time datetime="2013-10-09T00:00:00+08:00" class="assigned_time" style="text-align: right; display: block; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">2014-10-15</time>

