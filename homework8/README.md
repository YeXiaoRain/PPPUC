
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">Homework 8: Trees</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time class="due_time" datetime="2014-11-30T23:59:59+08:00" style="font-weight: bold;">2014-11-30 23:59 UTC+8</time></span><br style="font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Introduction</h4>
<div>
<p style="margin: 8px 0px;">In this homework, there are two problems: "Rebuild Binary Trees" and "Red Black Tree". You should choose one of the problems to solve. If you upload solutions to both problems, your final score will be the highest one.</p>
<p style="margin: 8px 0px;">Considering the difficulty, final score of the second problem will be multiplied by a factor of 1.2(i.e. if your score of problem 2 is 80, your final score is 80*1.2=96).</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Problem I: Rebuild Binary Trees</h4>
<a class="assignment_ref" href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework8/Demo.tar.gz" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; background: rgb(204, 204, 204);">Test Cases</a>
<div>
<p style="margin: 8px 0px;">When we are looking at a binary tree, we can write down its preorder traversal with no hesitation, as well as its inorder and postorder traversal.</p>
<p style="margin: 8px 0px;">For an instance, consider the tree below:</p>
<img src="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework8/tree.png" style="margin-left: 32px;">
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">Preorder traversal: 1 2 4 5 3 6<br>Inorder travesral: 4 2 5 1 3 6<br>Postorder traversal: 4 5 2 6 3 1<br></code></p>
<p style="margin: 8px 0px;">However, can we rebuild a binary tree according to its traversals? Knowledge has told us that we can rebuild a binary by its preorder and inorder traversal, or we can do this by its inorder and postorder traversal.</p>
<p style="margin: 8px 0px;">Thus in this problem, your goal is to rebuild a binary tree according to its preorder and inorder traversal.</p>
<div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Input/Output Format:</h4>
<div>
<p style="margin: 8px 0px;">Input file looks like this:</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">T<br>L1<br>P1 P2 P3...PL1<br>I1 I2 I3...IL1<br>L2<br>P1 P2 P3...PL2<br>I1 I2 I3...IL2<br>...<br>LT<br>P1 P2 P3...PLT<br>I1 I2 I3...ILT<br></code></p>
<p style="margin: 8px 0px;">Where T denotes the number of test cases in this file, followed by T test cases. In each test case, there are three lines: first line is the number of nodes in the tree, second line is preorder traversal of the tree and third line stands for inorder traversal.</p>
<p style="margin: 8px 0px;">e.g.</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">3<br>2<br>1 2<br>2 1<br>3<br>1 2 3<br>2 3 1<br>8<br>3 1 5 6 9 2 4 8<br>1 6 5 9 3 2 8 4<br></code></p>
<p style="margin: 8px 0px;"><b>Note:</b>We guarantee that every number in each traversal is a unique integer.</p>
<p style="margin: 8px 0px;">Output file contains T lines(As the number of parts in input file), each line denotes the postorder traversal of the tree you just rebuild.</p>
<p style="margin: 8px 0px;"><b>Note:</b>Every adjacent value should be separated by ' '(space).</p>
<p style="margin: 8px 0px;">e.g.(Suppose input file is the example above)</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">2 1<br>3 2 1<br>6 9 5 1 8 4 2 3<br></code></p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Use main() function arguments:</h4>
<div>
<p style="margin: 8px 0px;">You are free to write all your codes you like. But you should keep in mind that your program should accept 2 arguments: input file name and output file name.</p>
<p style="margin: 8px 0px;">If you forget how to do this, you may refer to the instruction of Lab2.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Scoring Rules:</h4>
<div>
<p style="margin: 8px 0px;">1.There are totally 20 test cases, each takes 5 points in 100.</p>
<p style="margin: 8px 0px;">2.The length of each traversal will never be longer than 100 nodes.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand In</h4>
<p style="margin: 8px 0px;">You only need to upload your sorce codes as a zip file to</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/homework8_1/<br>Username: solftwarewry, Password: public<br>Filename: 5130379001.zip<br></code></p>
<p style="margin: 8px 0px;">If you have any question or bugs to report, please ask on QA or contact&nbsp;<a href="mailto:babyfish92@163.com" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">babyfish92@163.com</a></p>
</div>
<br><br>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Problem II: Red Black Tree</h4>
<a class="assignment_ref" href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework8/starter.zip" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; background: rgb(204, 204, 204);">Download Starter Files</a>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">In this problem,you will implement redblack tree's remove method.</p>
<p style="margin: 8px 0px;">The scheme code is in<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">RedBlackTree.h</code>You need to write your code in<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">void remove( const Comparable &amp; x )</code></p>
<p style="margin: 8px 0px;"><strong style="color: red;">Note</strong>: We have provided the insert method and some other useful functions for you to startup.You can read the scheme code to find out whether you can use them to help solve the problem.</p>
<p style="margin: 8px 0px;">Yet,you are free to change the code and maybe totally reimplementing the red black tree,except that you&nbsp;<strong style="color: red;">should not change the public interface</strong>&nbsp;defined in&nbsp;<code>RedBlackTree.h</code>.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Score</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You can use the following command to test your program.</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">make score</code><strong>Note that we will use our own version of&nbsp;<code>TestRedBlackTree.cpp</code>to test your implementation.</strong></div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand in</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You only need to submit the&nbsp;<code>RedBlackTree.h</code>.</p>
<p style="margin: 8px 0px;">Submit your code as a zip file to</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/homework8/<br>Username: azard5, Password: public<br>Filename: 5130379001_homework8.zip</code></p>
<p style="margin: 8px 0px;">If you have any question or find some bugs, please ask on QA or contact&nbsp;<a href="mailto:wxdwfc@sjtu.edu.cn" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">wxdwfc@sjtu.edu.cn</a></p>
<strong style="color: red;">Do not submit to the wrong ftp!</strong></div>
<time class="assigned_time" datetime="2014-11-12T23:59:59+08:00" style="text-align: right; display: block;">2014-11-12</time></div>
</div>
