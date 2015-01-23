
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">Lab 4: Huffman Encoding</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time datetime="2014-12-13T23:59:59+08:00" class="due_time" style="font-weight: bold; color: red;">2014-12-13 23:59 UTC+8</time></span><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/lab4/lab4.zip" class="assignment_ref" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background: rgb(204, 204, 204);">Download Starter Files</a><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/lab4/lab4.pdf" class="assignment_ref" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background: rgb(204, 204, 204);">Slides</a>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Introduction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Huffman encoding is an example of a lossless compression algorithm that works particularly well on text and, in fact, can be applied to any type of file. It can reduce the storage required by a third or half or even more in some situations.</p>
<p style="margin: 8px 0px;">You are to write a program that allows the user to compress and decompress files using the standard Huffman algorithm for encoding and decoding.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hints</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Compressing a file will require reading through the file twice: first to count the characters, and then again when processing each character as part of writing the compressed output.</p>
<p style="margin: 8px 0px;">When writing the bit patterns to the compressed file, note that you do not write the ASCII characters '0' and '1' (that wouldn't do much for compression!), instead the bits in the compressed form are written one-by-one.</p>
<p style="margin: 8px 0px;">You are responsible for freeing memory. Make sure not to leak any tree nodes, and if you allocate any extra memory, be sure to deallocate it!</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Grading</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Your implementation will be evaluated using score in Test folder. You can evaluate your implementation by yourself. Try "./score " to evaluate your program. For trace 04 ~ 09, your compression ratio should be lower than 100%.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand-in</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You should work in Compression folder. You may add or modify files in this folder. Only keep your Makefile can produce executable file named Compression correctly when we type make in this folder. You should&nbsp;<strong>only turn in your Compression folder within a zip file</strong>&nbsp;to this ftp address:</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/lab4/<br>Username: azard5, Password: public<br>Filename: your_student_id.zip</code>
<p style="margin: 8px 0px;">Remember to run make clean before your turn-in.</p>
<p style="margin: 8px 0px;">If you have any question, please contact&nbsp;<a href="mailto:azardf4yy@gmail.com" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">azardf4yy@gmail.com</a></p>
</div>
<time datetime="2014-11-24T00:00:00+08:00" class="assigned_time" style="text-align: right; display: block;">2014-11-24</time></div>
