
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">Homework 2: Using Template</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time class="due_time" datetime="2014-09-23T23:59:59+08:00" style="font-weight: bold;">2014-09-23 23:59 UTC+8</time></span><a class="assignment_ref" href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/homework2/homework2.zip" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background: rgb(204, 204, 204);">Download Starter Files</a><br style="font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px; color: red;">You can find your grade of homework2 on grade system now. If you have any question about it, please contact&nbsp;<a href="mailto:frankfzw@sjtu.edu.cn" style="color: rgb(34, 102, 187); text-decoration: none; outline-style: none;">frankfzw@sjtu.edu.cn</a>&nbsp;ASAP</h5>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px; color: red;">Notiification: Please redownload the starter files if you can't "make"</h5>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Introduction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">In homework 2, you are expected to implement a simplified version of class&nbsp;<code>Vector</code>. Details of what interface you should implement will be discussed in detail in the following sections. Since it is a simplified version of vector, you do NOT need to implement&nbsp;<code>iterator</code>,<code>alloctor</code>&nbsp;or thread-safe&nbsp;<code>mutex</code>.</p>
<p style="margin: 8px 0px;"><strong>Note 1:&nbsp;</strong>Unless otherwise mentioned, we do NOT use Stanford library in our homework.</p>
<p style="margin: 8px 0px;"><strong>Note 2:&nbsp;</strong>You only need to modify Vector.h.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Implementation Specification</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Methods that you should implement are talked below. You should use new and delete to manage memory instead of using any other collector class such as&nbsp;<code>std::vector</code>.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">(default constructor)</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">Vector();</code>
<p style="margin: 8px 0px;">Constructs an empty container, with no elements.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">(fill constructor)</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">Vector(int size, const T&amp; val);</code>
<p style="margin: 8px 0px;">Constructs a container with n elements. Each element is a copy of&nbsp;<code>val</code>.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">(copy constructor)</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">Vector(const Vector&amp; x);</code>
<p style="margin: 8px 0px;">Constructs a container with a copy of each of the elements in x, in the same order.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">(destructor)</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">~Vector();</code>
<p style="margin: 8px 0px;">Destroys the container object.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">operator=</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">Vector&lt;T&gt;&amp; operator=(const Vector&lt;T&gt;&amp; x);</code>
<p style="margin: 8px 0px;">Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">size</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">int size() const;</code>
<p style="margin: 8px 0px;">Returns the number of elements in the vector. This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">empty</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">bool empty() const;</code>
<p style="margin: 8px 0px;">Returns whether the vector is empty.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">operator[]</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">T&amp; operator [](int pos);</code>
<p style="margin: 8px 0px;">Returns a reference to the element at position n in the vector container. if the requested position is out of range, the behavior is undefined</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">resize</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">void resize(size_t n, T val);</code>
<p style="margin: 8px 0px;">Resizes the container so that it contains n elements.</p>
<p style="margin: 8px 0px;">If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).</p>
<p style="margin: 8px 0px;">If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. The new elements are initialized as copies of&nbsp;<code>val</code>.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">push_back</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">void push_back(const T&amp; val);</code>
<p style="margin: 8px 0px;">Adds a new element at the end of the vector, after its current last element. The content of&nbsp;<code>val</code>&nbsp;is copied (or moved) to the new element.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">sort</h5>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">void sort();</code>
<p style="margin: 8px 0px;">This method is designed for you to learn the template specialization</p>
<p style="margin: 8px 0px;">You should implement two version of this method</p>
<p style="margin: 8px 0px;">One for the general template, sort the elements in&nbsp;<code>Vector</code>&nbsp;in increasing order and output the result in stdout</p>
<p style="margin: 8px 0px;">For instance: the original elements in&nbsp;<code>Vector</code>&nbsp;is&nbsp;<code>4&nbsp;3&nbsp;1&nbsp;2</code></p>
<p style="margin: 8px 0px;">The output should be&nbsp;<code>1&nbsp;2&nbsp;3&nbsp;4</code></p>
<p style="margin: 8px 0px;">The other is specialization of string, you should sort the string in lexicographical increasing order from tail to head!</p>
<p style="margin: 8px 0px;">For instance: the original elements in&nbsp;<code>Vector</code>&nbsp;is&nbsp;<code>"abc"&nbsp;"abb"&nbsp;"caba"&nbsp;"caca"</code></p>
<p style="margin: 8px 0px;">The output should be&nbsp;<code>"caba"&nbsp;"caca"&nbsp;"abb"&nbsp;"abc"</code></p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Test</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Your output should be same as&nbsp;<code>SampleOutput</code>&nbsp;file. You can test your homework by using&nbsp;<code>testVector</code>. We may use different&nbsp;<code>testVector</code>and&nbsp;<code>runVector.cpp</code>&nbsp;to test your answers.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Socre</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You will get full credit if you pass our testVector</p>
<p style="margin: 8px 0px;">Late committing will be punished</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand in</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You only need to turn in your&nbsp;<code>Vector.h</code>&nbsp;file.</p>
<p style="margin: 8px 0px;">Submit your file to</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/homework2/<br>Username: azard5, Password: public<br>Filename: 5130379001_Vector.h</code></p>
<p style="margin: 8px 0px;">If you have any question or find some bugs, please contact&nbsp;<a href="mailto:frankfzw@sjtu.edu.cn" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">frankfzw@sjtu.edu.cn</a></p>
</div>
</div>
