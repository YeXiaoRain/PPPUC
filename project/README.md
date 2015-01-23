
<h3 style="font-family: Simsun; line-height: normal;">大作业：简易数据存储系统</h3>
<span class="assignment_due" style="font-family: Simsun; font-size: medium; line-height: normal;">due on&nbsp;<time datetime="2015-1-3T23:59:59+08:00" class="due_time" style="color: red;">2015-1-3 23:59 UTC+8</time></span><span style="font-family: Simsun; font-size: medium; line-height: normal;">&nbsp;</span><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/project/project.pdf" class="assignment_ref" target="_blank" style="font-family: Simsun; font-size: medium; line-height: normal;">查看PDF</a><span style="font-family: Simsun; font-size: medium; line-height: normal;">&nbsp;</span><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/project/project.pptx" class="assignment_ref" target="_blank" style="font-family: Simsun; font-size: medium; line-height: normal;">Slides</a><span style="font-family: Simsun; font-size: medium; line-height: normal;"></span>
<div class="in" style="font-family: Simsun; font-size: medium; line-height: normal;">发布日期：2014年12月06日<br>期末检查：2015年01月03日（第16周周六）<br>最终检查1：2015年01月13日（第18周周二）<br>最终检查2：2015年01月16日（第18周周五）<br><br>若发现网页与PDF内容不一致的，<mark>以网页为准</mark>。<br>大作业的要求不会变更，大作业描述的变更会在此显示。<br><strong style="color: red;">2014/12/29: 增加最终检查时间</strong></div>
<br style="font-family: Simsun; font-size: medium; line-height: normal;">
<div class="in" style="font-family: Simsun; font-size: medium; line-height: normal;">
<h4>1.	概述</h4>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 程序设计2（数据结构）大作业，强调数据结构的选择和对性能的分析。涉及查找、树、散列等操作。目的在于让同学们利用所学的知识，设计并构建一个简易的数据存储系统，进一步理解和掌握基本的数据结构和算法。</p>
</div>
<h4>2.	功能要求</h4>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 你需要完成对数据的增删改查。详细描述，就是每一组数据都包含一个名字和其内容，你实现的存储系统需要将每组数据的内容保存在磁盘中，并且能够根据名字查找对应的内容，进行查看，删除，修改操作。数据存储、索引的形式有较大的灵活性，你可以选择合适的数据结构进行实现。所以你需要在最后提交的文档中描述你使用了怎样的数据结构，效果如何；以及磁盘中数据和索引的组织格式。</p>
<h5>2.1.	数据文件</h5>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 数据文件存储所保存数据的内容，保证下一次运行时能够从磁盘文件中读取。数据文件的格式可以自行设计，包括文件头，数据描述信息等。你的系统应提供对数据进行增删改查的接口，接口可参考附录资料，也可以自行设计。</p>
</div>
<h5>2.2.	索引文件</h5>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 除了数据以外，还需要考虑对数据进行索引，以便根据名字能快速找到对应的数据内容。通过索引可以快速定位数据在文件中的位置并获取相关数据。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 你可以在磁盘上采用树、散列等数据结构保存索引信息，具体实现自行设计，自由度较大。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 你可以将全部索引保存在一个文件中，或者保存在多个文件中，甚至采用二级索引以便减小单个索引文件的大小。数据文件你也可以将其全部保存在一个文件中，或者保存在多个文件中。但不允许以每组数据（名字和其内容）为单位单独保存在一个文件中，<mark>索引和数据文件需要分开</mark>。</p>
</div>
<h5>2.3.	一致性刷新方法设计</h5>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 因为数据量较大，系统运行时不能够将所有的数据存放在内存中，因此一份数据可能同时出现在磁盘和内存中。你需要考虑何时对文件进行读写以便保持文件的一致性，且保证运行效率。</p>
</div>
</div>
<h4>3.	系统测试</h4>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 关于测试的程序，你的测试应该独立于实现的数据存储系统，并且应该直接针对该系统的API进行编写，不需要通过读取测试脚本等外部IO方式进行测试。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 具体的测试内容可以自行设计，至少包括增删改查操作。可参考附录[1]中的测试。</p>
<h5>3.1.	正确性测试</h5>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 正确性测试既包括结果正确没有引发程序的异常退出或内存泄露，也包括符合预期的性能要求。你需要自行书写测试内容，测试数据可以用使用一些随机数据生成工具。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 测试应涵盖程序的各个操作，并且应当保证数据量<mark>不少于100万条</mark>。</p>
</div>
<h5>3.2.	性能测试</h5>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 性能测试与正确性测试要求类似，但注重考查程序的性能。同样需要进行<mark>不少于100万</mark>数据量的测试，可以记录不同数据量的操作所耗费的时间，不同数据规模时进行同样的操作所耗费的时间。并使用相关绘图软件绘制时间-数据量的散点图或者拟合图，并对结果图进行分析解释。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 注意，由于每个人的机器配置不一样，和其他人比较性能是没有意义的，我们也不会根据你的性能进行评分，我们关注的是你通过测试可以证明程序符合设计的预期，并且通过测试可以发现在使用和不使用索引的性能差异，以及不同数据结构的性能差异。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 提交作业时，需要包含测试文件和测试报告，测试报告应描述你的测试过程，测试结果图和对测试结果的分析。</p>
</div>
</div>
<h4>4.	其他限制要求</h4>
<div class="in">
<h5>4.1.	自行实现关键数据结构</h5>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 大作业程序中使用的关键数据结构，例如散列、B树需要自行实现，文件的一致性刷新也需要自行实现，不可使用任何已有的库。</p>
</div>
<h5>4.2.	函数库的使用</h5>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 不涉及关键数据结构的部分，可以随意使用你喜欢的库进行开发。注意不要实现过多无用的功能而忽视了作业要求的部分，这对你的成绩不会有任何有益的影响。</p>
</div>
<h5>4.3.	开发和编译环境</h5>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 程序需要用C/C++实现，答辩时需要大家演示自己的系统，程序为单机程序，不需要实现多线程、网络通讯等功能。</p>
</div>
</div>
<h4>5.	检查</h4>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 一共有两次检查的时间。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 如果你在<mark>期末检查前完成了全部要求</mark>，可以直接给我们进行检查，通过后不需要第二次检查。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 如果你在<mark>期末检查没有完成全部要求</mark>，务必在最终提交时给我们进行检查，最终提交是大作业的最后期限。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 具体的检查安排，包括检查地点，会在检查前公布在课程网站上，请留意。</p>
</div>
<h4>6.	评分</h4>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 大作业占这门课程总成绩的20%。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 满分20分中，存储系统的实现占10分，测试和文档占10分。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 如果你的索引实现了B树等较为复杂的数据结构，或者在某一部分使用了较为高级的算法和数据结构，存储系统的实现部分的10分都可拿到满分。如果只使用了散列表作为索引，功能上的增删改查做到了，保证了正确性，这部分至少能拿9分。其他情况的得分视实现的难度和合理性而定。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 测试和文档部分实现了正确性测试，性能测试描述中的部分，并且书写了详细的描述实现和解释测试结果的文档，能够得到9分以上。具体得分视测试和文档的覆盖面和完整性而定。</p>
</div>
<h4>7.	提示和建议</h4>
<div class="in">
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 一般来说，测试和修复错误的时间会占到开发总时间的一半以上，尤其涉及到一些较为复杂的算法时测试所占的比重往往会更多。所以请尽早着手完成作业，注意合理安排好自己的时间。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 考虑使用二进制文件读写而非文本文件读写，这样既可以提高程序效率，又可以降低开发难度。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 虽然我们不允许你直接使用已有的库来实现系统中关键的数据结构，但建议你查阅相关资料，参考已有的数据结构而非从头开始自己的设计。例如你可以去了解数据库系统都是用了怎样的方式管理数据，虽然数据库系统可能有很多较为复杂而我们不需要关心的高级话题（如并发控制），但对于数据的存储和索引，这些设计对我们很具有参考价值。</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 建议你在开始书写程序之前就对你要使用的数据结构有所设想，以避免在开发过程中，因为要使用某种数据结构而出现对已经完成的代码大量的返工。</p>
</div>
<h4>8.提交及Q&amp;A</h4>
<div class="in">
<p>请在检查之前将你的代码和文档提交到FTP上，命名为: 5130379001_project.zip<br><code class="codep">ftp://public.sjtu.edu.cn/upload/project/<br>Username: azard5, Password: public<br>Filename: 5130379001_project.zip&nbsp;</code>如果有其他疑问，请在Q&amp;A上提出，或者联系助教：&nbsp;<br>付周旺：<a href="mailto:frankfzw@gmail.com">frankfzw@gmail.com</a>&nbsp;<br>熊伟伦：<a href="mailto:azardf4yy@gmail.com">azardf4yy@gmail.com</a></p>
</div>
<h4>9.参考及附录</h4>
<div class="in"><ol>
<li><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/project/attachment1.pdf" target="_blank">数据库函数库</a></li>
<li>SQLite:&nbsp;<a href="http://www.sqlite.org/" target="_blank">http://www.sqlite.org/</a></li>
<li>Oracle Berkely DB:&nbsp;<a href="http://www.oracle.com/technetwork/database/berkeleydb/index.html" target="_blank">http://www.oracle.com/technetwork/database/berkelydb/index.html</a></li>
<li>Google C++ Style Guide:&nbsp;<a href="http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml" target="_blank">http://www.google-styleguide.googlecode.com/svn/trunk/cppguide.xml</a></li>
<li><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/project/attachment5.pdf" target="_blank">JPL Coding Standard</a></li>
<li><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/project/attachment6.pdf" target="_blank">华为编程规范</a></li>
</ol></div>
<time datetime="2014-12-6T00:00:00+08:00" class="assigned_time">2014-12-6</time></div>

