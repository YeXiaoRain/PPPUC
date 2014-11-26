
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background-color: rgb(241, 242, 243);">Lab 3: Minimal BASIC Interpreter</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time datetime="2014-11-27T23:59:59+08:00" class="due_time" style="font-weight: bold;">2014-11-27 23:59 UTC+8</time></span><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/lab3/lab3.pdf" class="assignment_ref" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background: rgb(204, 204, 204);">view as PDF</a><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/lab3/lab3.tar.gz" class="assignment_ref" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background: rgb(204, 204, 204);">Download Starter Files</a><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/lab3/slides/" class="assignment_ref" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; background: rgb(204, 204, 204);">Slides</a>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', ºÚÌå-¼ò, 'MS Yahei', Î¢ÈíÑÅºÚ, STXihei, »ªÎÄÏ¸ºÚ, 'WenQuanYi ZenHei', ÎÄÈªæäÕýºÚÌå, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Introduction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">In this assignment, your mission is to build a minimal BASIC interpreter. You may start with the code for the expression evaluator (aka calculator) in Computer Programming I (SE105).</p>
<p style="margin: 8px 0px;">You are also free to use&nbsp;<code>StandfordCPPLib</code>&nbsp;and other&nbsp;<code>STL</code>&nbsp;functions.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">BASIC Language and Interpreter</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">The programming language BASIC - the name is an acronym for Beginner's All-purpose Symbolic Instruction Code - was developed in the mid-1960s at Dartmouth College by John Kemeny and Thomas Kurtz.</p>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">A Plus B</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">In BASIC, a program consists of a sequence of numbered statements, as illustrated by the simple program below:</p>
<code class="codep basic" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px; background-image: initial; background-attachment: initial; background-size: initial; background-origin: initial; background-clip: initial; background-position: initial; background-repeat: initial;"><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">10</span>&nbsp;<span class="remark" style="color: rgb(34, 119, 51); font-style: italic;">REM&nbsp;Program&nbsp;to&nbsp;add&nbsp;two&nbsp;numbers</span><br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">20</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">INPUT</span>&nbsp;n1<br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">30</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">INPUT</span>&nbsp;n2<br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">40</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">LET</span>&nbsp;total&nbsp;<span class="operator" style="color: rgb(170, 153, 170);">=</span>&nbsp;n1&nbsp;<span class="operator" style="color: rgb(170, 153, 170);">+</span>&nbsp;n2<br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">50</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">PRINT</span>&nbsp;total<br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">60</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">END</span></code></div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Lexical</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Identifiers are formed by one or more letters. Keywords that are reserved words in the language and cannot be used as identifiers. Integer literals are composed of digits only. This language is case-insensitive, which means&nbsp;<code>i</code>&nbsp;and&nbsp;<code>I</code>&nbsp;are the same variable, and&nbsp;<code>IF</code>,&nbsp;<code>if</code>,<code>If</code>, and even&nbsp;<code>iF</code>&nbsp;have the same meaning.</p>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Line Numbers</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">The&nbsp;<strong>line numbers&nbsp;<em>at the beginning of the line</em></strong>&nbsp;establish the sequence of operations in a program. In the absence of any control statements to the contrary, the statements in a program are&nbsp;<strong>executed in ascending numerical order starting at the lowest number</strong>.</p>
<p style="margin: 8px 0px;">Line numbers are also used to provide a simple editing mechanism.&nbsp;<strong>Statements need not be entered in order</strong>, because the line numbers indicate their relative position. Moreover, as long as the user has left gaps in the number sequence, new statements can be added in between other statements</p>
<p style="margin: 8px 0px;">For example, to change the program that adds two numbers into one that adds three numbers, you would need to make the following changes:</p>
<p style="margin: 8px 0px;">1. Add a new line to read in the third value by typing in the command&nbsp;<code class="basic" style="background-image: initial; background-attachment: initial; background-size: initial; background-origin: initial; background-clip: initial; background-position: initial; background-repeat: initial;"><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">35</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">INPUT</span>&nbsp;n3</code>&nbsp;. This statement is inserted into the program between line 30 and line 40.</p>
<p style="margin: 8px 0px;">2. Type in a new assignment statement, as&nbsp;<code class="basic" style="background-image: initial; background-attachment: initial; background-size: initial; background-origin: initial; background-clip: initial; background-position: initial; background-repeat: initial;"><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">40</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">LET</span>&nbsp;total&nbsp;<span class="operator" style="color: rgb(170, 153, 170);">=</span>&nbsp;n1&nbsp;<span class="operator" style="color: rgb(170, 153, 170);">+</span>&nbsp;n2&nbsp;<span class="operator" style="color: rgb(170, 153, 170);">+</span>&nbsp;n3</code>&nbsp;. This statement replaces the old line 40 with the updated version.</p>
<p style="margin: 8px 0px;">The standard mechanism for deleting lines was to&nbsp;<strong>type in a line number with nothing after it</strong>&nbsp;on the line. Note that this operation actually&nbsp;<strong>deleted the line</strong>&nbsp;and did not simply replace it with a blank line that would appear in program listings.</p>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Sequential Statements</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px;">

<tbody>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); width: 8em;"><strong>REM</strong></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This statement is used for comments.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>LET</strong>&nbsp;<em>var</em>&nbsp;=&nbsp;<em>exp</em></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This statement is BASIC's assignment statement.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>PRINT</strong>&nbsp;<em>exp</em></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This statement print the value of the expression on the console and&nbsp;<strong>then print a newline character</strong>.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>INPUT</strong>&nbsp;<em>var</em></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This statement print a&nbsp;<strong>prompt consisting of the string " ? "</strong>&nbsp;and then to read in a value to be stored in the variable.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>END</strong></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">Marks the end of the program. Execution halts when this line is reached. Execution&nbsp;<strong>also stops if the program continues past the last numbered line</strong>.</td>
</tr>

</tbody>

</table>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Control Statements</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">For example, the following BASIC program simulates a countdown from 10 to 0:</p>
<code class="codep basic" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px; background-image: initial; background-attachment: initial; background-size: initial; background-origin: initial; background-clip: initial; background-position: initial; background-repeat: initial;"><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">10</span>&nbsp;<span class="remark" style="color: rgb(34, 119, 51); font-style: italic;">REM&nbsp;Program&nbsp;to&nbsp;simulate&nbsp;a&nbsp;countdown</span><br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">20</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">LET</span>&nbsp;T&nbsp;<span class="operator" style="color: rgb(170, 153, 170);">=</span>&nbsp;<span class="number" style="color: rgb(170, 34, 153);">10</span><br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">30</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">IF</span>&nbsp;T&nbsp;<span class="operator" style="color: rgb(170, 153, 170);">&lt;</span>&nbsp;<span class="number" style="color: rgb(170, 34, 153);">0</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">THEN</span>&nbsp;<span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">70</span><br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">40</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">PRINT</span>&nbsp;T<br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">50</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">LET</span>&nbsp;T&nbsp;<span class="operator" style="color: rgb(170, 153, 170);">=</span>&nbsp;T&nbsp;<span class="operator" style="color: rgb(170, 153, 170);">-</span>&nbsp;<span class="number" style="color: rgb(170, 34, 153);">1</span><br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">60</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">GOTO</span>&nbsp;<span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">30</span><br><span class="linum" style="color: rgb(51, 119, 170); font-weight: bold;">70</span>&nbsp;<span class="keyword" style="color: rgb(119, 136, 51); font-weight: bold;">END</span></code>
<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px;">

<tbody>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); width: 12em;"><strong>GOTO</strong>&nbsp;<em>n</em></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This statement transfers control unconditionally to line&nbsp;<em>n</em>&nbsp;in the program. If line&nbsp;<em>n</em>&nbsp;<strong>does not exist</strong>, your BASIC interpreter should&nbsp;<strong>generate an error message</strong>&nbsp;informing the user of that fact.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>IF</strong>&nbsp;<em>exp cmp exp</em>&nbsp;<strong>THEN</strong>&nbsp;<em>n</em></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This statement performs a conditional transfer of control. On encountering such a statement, the BASIC interpreter begins by evaluating condition, which in the minimal version of BASIC consists of two arithmetic expressions joined by one of the operators &lt;, &gt;, or =. If the result of the comparison is true, control passes to line n,<strong>&nbsp;just as in the GOTO statement</strong>; if not, the program continues with the next line in sequence.</td>
</tr>

</tbody>

</table>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Expressions</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Expressions are used in LET, PRINT, and IF statements.</p>
<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px;">

<tbody>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); width: 6em;"><em>int_const</em></td>
<td rowspan="2" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">The simplest expressions are variables and integer constants.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px; border-style: solid none; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><em>var</em></td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>(</strong>&nbsp;<em>exp</em>&nbsp;<strong>)</strong></td>
<td rowspan="2" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">These may be combined into larger expressions by enclosing an expression in parentheses or by joining two expressions with the operators +, -, *, and /, just as in the interpreter presented in the reader.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px; border-style: solid none; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><em>exp</em>&nbsp;<em>op</em>&nbsp;<em>exp</em></td>
</tr>

</tbody>

</table>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Executed Directly</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">The LET, PRINT, and INPUT statements can be executed directly by typing them without a line number, in which case they are evaluated immediately. Thus, if you type in "PRINT 2 + 2" your program should respond immediately with 4.</p>
<p style="margin: 8px 0px;">The statements GOTO, IF, REM, and END are legal only if they appear as part of a program, which means that they must be given a line number.</p>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">BASIC Interpreter</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">These commands control the BASIC interpreter, which don't contained in BASIC program.</p>
<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px;">

<tbody>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>RUN</strong></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This command starts program execution&nbsp;<strong>beginning at the lowest-numbered line</strong>.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>LIST</strong></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This command lists the steps in the program&nbsp;<strong>in numerical sequence</strong>.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>CLEAR</strong></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This command deletes all program and variables.</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>QUIT</strong></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This command exits from the BASIC interpreter by calling exit(0).</td>
</tr>

<tr style="border-collapse: collapse;">
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);"><strong>HELP</strong></td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);">This command provides a simple help message describing your interpreter.</td>
</tr>

</tbody>

</table>
</div>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Error Reporting</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">DIVIDE BY ZERO - Calculating some number divide by zero.</p>
<p style="margin: 8px 0px;">INVALID NUMBER - User types wrong value to answer INPUT statement.</p>
<p style="margin: 8px 0px;">VARIABLE NOT DEFINED - A variable used before assigned it.</p>
<p style="margin: 8px 0px;">LINE NUMBER ERROR - GOTO statement's line number not exist.</p>
<p style="margin: 8px 0px;">SYNTAX ERROR - Any other errors.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hints</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">1. Recall the&nbsp;<code>TokenScanner</code>&nbsp;in homework 1, it may help you in this lab</p>
<p style="margin: 8px 0px;">2. If you are not sure about some functions of the interpreter, try the Demo.</p>
<p style="margin: 8px 0px;">3. You only have to support the integer type of variables</p>
<p style="margin: 8px 0px;">4. If you want to include header files from StanfordCPPLib, add the "../StandfordCPPLib" before the name of header files. e.g.&nbsp;<code>#include "../StanfordCPPLib/tokenscanner.h"</code></p>
<p style="margin: 8px 0px;">5. You may found some "unreasonable" bugs in Demo, just make sure yours perform exactly same as the Demo, and you can report bugs&nbsp;<a href="http://tcloud.sjtu.edu.cn/course/se106/2014/qa/index.php?qa=203&amp;qa_1=lab3-bug%E6%B1%87%E6%80%BB%E4%BB%A5%E5%8F%8Abonus" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">here</a>&nbsp;in QA. You can hand in two versions of this lab if it is necessary, a naive one to pass our test and a better version with<strong>README</strong>&nbsp;to earn 10% score for bonus.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Grading</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Your implementation will be evaluated using&nbsp;<code>score</code>&nbsp;in&nbsp;<code>Test</code>&nbsp;folder. You can evaluate your implementation by yourself. Try "<code>./score -f -c</code>" to evaluate your program. Type&nbsp;<code>"./score -h</code>" for more details about our score program.</p>
<p style="margin: 8px 0px;">Make sure that you did&nbsp;<code>make</code>&nbsp;in&nbsp;<code>Basic</code>&nbsp;folder before running score.</p>
<p style="margin: 8px 0px;">You will get full score (100) if you pass this test. But&nbsp;<strong>DONOT</strong>&nbsp;try to change the test program or cheat, we will run&nbsp;<code>score</code>&nbsp;again and check your code manualy!</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand-in</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Your code must be written in C/C++. And you are not allowed to use compiler-compiler or any other tools to generate your codes. You should work in&nbsp;<code>Basic</code>&nbsp;folder. You may add or modify files in this folder. Only keep your Makefile produce executable file named<code>Basic</code>&nbsp;when we type&nbsp;<code>make</code>&nbsp;in this folder correctly. You should turn in your&nbsp;<code>Basic</code>&nbsp;folder by typing<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">./handin your_student_id</code>and then upload the corresponding your_student_id.tar.gz</p>
<p style="margin: 8px 0px;">Submit your file to</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">ftp://public.sjtu.edu.cn/upload/lab3/<br>Username: azard5, Password: public<br>Filename: your_student_id.tar.gz</code></p>
<p style="margin: 8px 0px;">Do NOT turn in&nbsp;<code>StanfordCPPLib</code>&nbsp;and other executable files.</p>
<p style="margin: 8px 0px;">If you have any question, please contact&nbsp;<a href="mailto:frankfzw@sjtu.edu.cn" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">frankfzw@sjtu.edu.cn</a></p>
</div>
<time datetime="2014-11-07T08:00:00+08:00" class="assigned_time" style="text-align: right; display: block;">2014-11-07</time></div>

