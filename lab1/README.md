
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; line-height: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">Lab 1: Fun with Collections</h3>
<span class="assignment_due" style="margin: -32px 0px 0px; line-height: 24px; font-size: 16px; float: right; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background-color: rgb(241, 242, 243);">due on&nbsp;<time datetime="2014-10-11T23:59:59+08:00" class="due_time" style="font-weight: bold;">2014-10-11 23:59 UTC+8</time></span><a href="http://tcloud.sjtu.edu.cn/course/se106/2014/assignments/lab1/lab1.tar.gz" class="assignment_ref" style="color: rgb(0, 0, 0); font-weight: bold; text-decoration: none; outline-style: none; display: block; float: right; padding: 8px 16px; line-height: 20px; font-size: 18px; margin: 8px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; background: rgb(204, 204, 204);">Download Starter Files</a>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; font-size: 16px; line-height: normal; background-color: rgb(241, 242, 243);">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;"><br>Introduction</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Now that you've been introduced to the handy Stanford C++ class library, it's time to put these objects to work! In your role as a client of these collections classes with the low-level details abstracted away, you can put your energy toward solving more interesting problems. In this assignment, your job is to write two short client programs that use these classes to do nifty things. The tasks may sound a little daunting at first, but given the power tools in your arsenal, each requires only a page or two of code. Let's hear it for abstraction!</p>
</div>
<p style="margin: 8px 0px;"><span style="color: red; font-weight: bold;">如果遇到无法运行demo的情况请重新下载下lab文件。更新的文件中有32位的和64位的版本。</span></p>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Problem I: Word ladders</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Introduction</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;"><mark style="background: rgb(204, 204, 204);">A&nbsp;<strong><em>word ladder</em></strong>&nbsp;is a connection from one word to another formed by changing one letter at a time with the constraint that at each step the sequence of letters still forms a&nbsp;<strong>valid</strong>&nbsp;word.</mark></p>
<p style="margin: 8px 0px;">For example, here is a word ladder connecting "<code>code</code>" to "<code>data</code>":</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">code -&gt; core -&gt; care -&gt; dare -&gt; date -&gt; data</code>
<p style="margin: 8px 0px;">That word ladder, however, is not the shortest possible one. Although the words may be a little less familiar, the following ladder is one step shorter:</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">code -&gt; cade -&gt; cate -&gt; date -&gt; data</code></div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Requirements</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;"><strong>Your job in this problem is to write a program that finds a minimal&nbsp;<em>word ladder</em>&nbsp;between two words.</strong>&nbsp;Your code will make use of several of the ADTs from Stanford C++ library, along with breadth-first search algorithm to find the shortest such sequence.</p>
<p style="margin: 8px 0px;">You may try out the demo program before you implement it. Your word ladder may be different from our demo, because there may be more than one shortest word ladder. You can test wether a word is valid English word by using&nbsp;<code>Lexicon</code>&nbsp;and&nbsp;<code>EnglishWords.dat</code>&nbsp;that we prepared.</p>
-
<p style="margin: 8px 0px;">Here, for example, is a sample run of the&nbsp;<code>word-ladder</code>&nbsp;program in operation:</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">
<pre style="padding: 0px; margin-top: 0px; margin-bottom: 0px;">Enter start word (RETURN to quit): <strong>hello</strong>
Enter destination word: <strong>world</strong>
Found ladder: hello hells heals weals weald woald world
Enter start word (RETURN to quit): </pre>
</code></div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Word Ladder Implementation</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;"><em>You can ignore this section if you have already known what breadth-first search is.</em></p>
<p style="margin: 8px 0px;">Finding a word ladder is a specific instance of a shortest-path problem, in which the challenge is to find the shortest path from a starting position to a goal. Shortest-path problems come up in a variety of situations such as routing packets in the Internet, robot motion planning, determining proximity in social networks, comparing gene mutations, and more.</p>
<p style="margin: 8px 0px;">One strategy for finding a shortest path is the classic algorithm known as breadth-first search, which is a search process that expands outward from the starting position, considering first all possible solutions that are one step away from the start, then all possible solutions that are two steps away, and so on, until an actual solution is found. Because you check all the paths of length 1 before you check any of length 2, the first successful path you encounter must be as short as any other.</p>
<p style="margin: 8px 0px;">For word ladders, the breadth-first strategy starts by examining those ladders that are one step away from the original word, which means that only one letter has been changed. If any of these single-step changes reach the destination word, you're done. If not, you can then move on to check all ladders that are two steps away from the original, which means that two letters have been changed. In computer science, each step in such a process is called a&nbsp;<em>hop</em>.</p>
<p style="margin: 8px 0px;">The breadth-first algorithm is typically implemented by using a queue to store partial ladders that represent possibilities to explore. The ladders are&nbsp;<code>enqueued</code>&nbsp;in order of increasing length. The first elements&nbsp;<code>enqueued</code>&nbsp;are all the one-hop ladders, followed by the two-hop ladders, and so on. Because queues guarantee first-in/first-out processing, these partial word ladders will be&nbsp;<code>dequeued</code>&nbsp;in order of increasing length.</p>
<p style="margin: 8px 0px;">To get the process started, you simply add a ladder consisting of only the start word to the queue. From then on, the algorithm operates by&nbsp;<code>dequeueing</code>&nbsp;the ladder from the front of the queue and determining whether it ends at the goal. If it does, you have a complete ladder, which must be minimal. If not, you take that partial ladder and extend it to reach words that are one additional hop away, and&nbsp;<code>enqueue</code>&nbsp;those extended ladders, where they will be examined later. If you exhaust the queue of possibilities without having found a completed ladder, you can conclude that no ladder exists.</p>
<p style="margin: 8px 0px;">Another issue that is a bit subtle is the restriction that you not reuse words that have been included in a previous ladder. One advantage of making this check is that doing so reduces the need to explore redundant paths. If there is a word ladder that begins with&nbsp;<code>cat -&gt; cot -&gt; con -&gt; cog</code>&nbsp;, then there must be a shorter one that, in effect, cuts out the middleman by eliminating the unnecessary word&nbsp;<code>con</code>. In fact, as soon as you've&nbsp;<code>enqueued</code>&nbsp;a ladder ending with a specific word, you never have to&nbsp;<code>enqueued</code>&nbsp;that word again.</p>
<p style="margin: 8px 0px;">The simplest way to implement this strategy is to keep track of the words that have been used in any ladder (which you can easily do using another lexicon) and ignore those words when they come up again. Keeping track of what words you've used also eliminates the possibility of getting trapped in an infinite loop by building a circular ladder.</p>
<p style="margin: 8px 0px;">One of the other questions you will need to resolve is what data structure you should use to represent word ladders. Conceptually, each ladder is just an ordered list of words, which should make your mind scream out "<code>Vector</code>!" (Given that all the growth is at one end, stacks are also a possibility, but vectors will be more convenient when you are trying to print out the results.) The individual components of the&nbsp;<code>Vector</code>&nbsp;are of type&nbsp;<code>string</code>.</p>
<p style="margin: 8px 0px;">It is possible to make the algorithm considerably more concrete by implementing it in pseudo code, which is simply a combination of actual code and English. The pseudo code for the word-ladder problem:</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">
<pre style="padding: 0px; margin-top: 0px; margin-bottom: 0px;"><em>Create an empty queue.</em>
<em>Add the start word to a new ladder.</em>
<em>Add the ladder to the queue.</em>
<strong>while</strong> (<em>the queue is not empty</em>) {
    <em>Dequeue the first ladder from the queue</em>.
    <strong>if</strong> (<em>the final word in this ladder is the destination word</em>) {
        <em>Return this ladder as the solution.</em>
    }
    <strong>for</strong> (<em>each word in the lexicon of English words that differs by one letter</em>) {
        <strong>if</strong> (<em>that word has not already been used in a ladder</em>) {
            <em>Create a copy of the current ladder.</em>
            <em>Add the new word to the end of the copy.</em>
            <em>Add the new ladder to the end of the queue.</em>
        }
    }
}
<em>Report that no word ladder exists.</em></pre>
</code></div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Grading</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Your implementation of this problem will be evaluated using&nbsp;<code>score</code>&nbsp;in&nbsp;<code>scores</code>&nbsp;folder.Try "<code>make score</code>" to help evaluate your program.The output information will show whether you have passed all the tests.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Note</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;"><mark style="background: rgb(204, 204, 204);">Please make sure that your program's in/output format matches demo program's format.Otherwise the evaluating program will fail to work.</mark></p>
<p style="margin: 8px 0px;">We will use our copy of evluation program to evaluate your score.</p>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Problem II: Random Writer</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Introduction</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">In the past few decades, computers have revolutionized student life. In addition to providing no end of entertainment and distractions, computers also have also facilitated much productive student work. However, one important area of student labor that has been painfully neglected is the task of filling up space in papers, Ph.D. dissertations, grant proposals, and recommendation letters with important sounding and somewhat sensible random sequences. Come on, you know the overworked TA/professor/reviewer doesn't have time to read too closely.</p>
<p style="margin: 8px 0px;">To address this burning need,&nbsp;<mark style="background: rgb(204, 204, 204);">the&nbsp;<strong><em>random writer</em></strong>&nbsp;is designed to produce somewhat sensible output by generalizing from patterns found in the input text.</mark>&nbsp;When you're coming up short on that 10-page paper due tomorrow, feed in the eight pages you already have written into the random writer, and "Voila!" another couple of pages appear. You can even feed your own&nbsp;<code>.cpp</code>&nbsp;files back into your program and have it build a new random program on...</p>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Requirements</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;"><strong>Your program is to read a source text, build an order-<em>k</em>&nbsp;Markov model for it, and generate random output that follows the frequency patterns of the model.</strong></p>
<p style="margin: 8px 0px;">First, you prompt the user for the name of a file to read for the source text and reprompt as needed until you get a valid name. (And you probably have a function like this lying around somewhere.) Now ask the user for what order of Markov model to use (a number from 1 to 10). This will control what seed length you are working with.</p>
<p style="margin: 8px 0px;">Use simple character-by-character reading on the file. As you go, track the current seed and observe what follows it. Your goal is to record the frequency information in such a way that it will be easy to generate random text later without any complicated manipulations.</p>
<p style="margin: 8px 0px;">Once the reading is done, your program should output&nbsp;<strong>2000 characters</strong>&nbsp;of random text generated from the model. For the initial seed, choose the sequence that appears&nbsp;<strong>most frequently</strong>&nbsp;in the source (e.g., if you are doing an order-4 analysis, the four-character sequence that is most often repeated in the source is used to start the random writing). If there are several sequences tied for most frequent, any of them can be used as the initial seed. Output the initial seed, then&nbsp;<strong>choose the next character based on the probabilities of what followed that seed in the source</strong>. Output that character, update the seed, and the process repeats until you have 2000 characters.</p>
<p style="margin: 8px 0px;">For example, consider an order-2 Markov model built from this sentence from Franz Kafka's&nbsp;<em>Metamorphosis</em>:</p>
<blockquote style="font-family: monospace;">As Gregor Samsa awoke one morning from uneasy dreams he found himself transformed in his bed into a gigantic insect.</blockquote>
<p style="margin: 8px 0px;">Here is how the first few characters might be chosen:</p>
<ul class="tl">
<li>The most commonly occurring sequence is the string&nbsp;<q style="font-family: monospace;">in</q>, which appears four times. This string therefore becomes the initial seed.</li>
<li>The next character is chosen based on the probability that it follows the seed&nbsp;<q style="font-family: monospace;">in</q>&nbsp;in the source. The source contains four occurrences of&nbsp;<q style="font-family: monospace;">in</q>, one followed by&nbsp;<q style="font-family: monospace;">g</q>, one followed by&nbsp;<q style="font-family: monospace;">t</q>, one followed by&nbsp;<q style="font-family: monospace;">s</q>, and one followed by a space. Thus, there should be a 1/4 chance each of choosing&nbsp;<q style="font-family: monospace;">g</q>,&nbsp;<q style="font-family: monospace;">t</q>,&nbsp;<q style="font-family: monospace;">s</q>, or space. Suppose space is chosen this time.</li>
<li>The seed is updated to&nbsp;<q style="font-family: monospace;">n&nbsp;</q>. The source contains one occurrence of&nbsp;<q style="font-family: monospace;">n&nbsp;</q>, which is followed by&nbsp;<q style="font-family: monospace;">h</q>. Thus the next character chosen is&nbsp;<q style="font-family: monospace;">h</q>.</li>
<li>The seed is now&nbsp;<q style="font-family: monospace;">&nbsp;h</q>. The source contains three occurrences of&nbsp;<q style="font-family: monospace;">&nbsp;h</q>, once followed by&nbsp;<q style="font-family: monospace;">e</q>, and twice followed by&nbsp;<q style="font-family: monospace;">i</q>. Thus, there is a 1/3 chance of choosing&nbsp;<q style="font-family: monospace;">e</q>&nbsp;and 2/3 for&nbsp;<q style="font-family: monospace;">i</q>. Imagine&nbsp;<q style="font-family: monospace;">i</q>&nbsp;is chosen this time.</li>
<li>The seed is now&nbsp;<q style="font-family: monospace;">hi</q>. The source contains two occurrences of&nbsp;<q style="font-family: monospace;">hi</q>, once followed by&nbsp;<q style="font-family: monospace;">m</q>, the other by&nbsp;<q style="font-family: monospace;">s</q>. For the next character, there is 1/2 chance of choosing&nbsp;<q style="font-family: monospace;">m</q>&nbsp;and 1/2 chance for&nbsp;<q style="font-family: monospace;">s</q>.</li>
</ul>
<p style="margin: 8px 0px;">If your program ever gets into a situation in which there are&nbsp;<strong>no characters to choose</strong>&nbsp;from (which can happen if the only occurrence of the current seed is at the exact end of the source), your program can just&nbsp;<strong>stop writing early</strong>.</p>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Details of Markov model</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;"><em>You can ignore this section if you have already known what Markov model is.</em></p>
<p style="margin: 8px 0px;">Random writing is based on an idea advanced by Claude Shannon in 1948 and subsequently popularized by A. K. Dewdney in his<em>Scientific American</em>&nbsp;column in 1989. Shannon's famous paper introduces the idea of a Markov model for English text. A&nbsp;<strong>Markov model</strong>&nbsp;is a statistical model that describes the future state of a system based on the current state and the conditional probabilities of the possible transitions. Markov models have a wide variety of uses, including recognition systems for handwriting and speech, machine learning, and bioinformatics. Even Google's PageRank algorithm has a Markov component to it. In the case of English text, the Markov model is used to describe the possibility of a particular character appearing given the sequence of characters seen so far. The sequence of characters within a body of text is clearly not just a random rearrangement of letters, and the Markov model provides a way to discover the underlying patterns and, in this case, to use those patterns to generate new text that fits the model.</p>
<p style="margin: 8px 0px;">First, consider generating text in total randomness. Suppose you have a monkey at the keyboard who is just as likely to hit any key as another. While it is theoretically possible - given enough monkeys, typewriters, and ages of the universe - that this sort of random typing would produce a work of Shakespeare, most output will be gibberish that makes pretty unconvincing English:</p>
<div class="in" style="margin: 0px 0px 0px 16px;">

<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px; width: 989px;">

<tbody>

<tr style="border-collapse: collapse;">
<td width="80" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);">No model</td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);"><blockquote style="font-family: monospace; margin: 0px;">aowk fh4.s8an zp[q;1k ss4o2mai/</blockquote></td>
</tr>

</tbody>

</table>
</div>
<p style="margin: 8px 0px;">A simple improvement is to gather information on character frequency and use that as a weight for choosing the next letter. In English text, not all characters occur equally often. Better random text would mimic the expected character distribution. Read some input text (such as Mark Twain's&nbsp;<em>Tom Sawyer</em>, for example) and count the character frequencies. You'll find that spaces are the most common, that the character&nbsp;<q style="font-family: monospace;">e</q>&nbsp;is fairly common, and that the character&nbsp;<q style="font-family: monospace;">q</q>&nbsp;is rather uncommon. Suppose that space characters represent 16% of all characters in&nbsp;<em>Tom Sawyer</em>,&nbsp;<q style="font-family: monospace;">e</q>&nbsp;just 9%, and&nbsp;<q style="font-family: monospace;">q</q>&nbsp;a mere .04% of the total. Using these weights, you could produce random text that exhibited these same probabilities. It wouldn't have a lot in common with the real Tom Sawyer, but at least the characters would tend to occur in the proper proportions. In fact, here's an example of what you might produce:</p>
<div class="in" style="margin: 0px 0px 0px 16px;">

<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px; width: 989px;">

<tbody>

<tr style="border-collapse: collapse;">
<td width="80" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);">Order 0</td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);"><blockquote style="font-family: monospace; margin: 0px;">rla bsht eS ststofo hhfosdsdewno oe wee h .mr ae irii ela iad o r te u t mnyto onmalysnce, ifu en c fDwn oee iteo</blockquote></td>
</tr>

</tbody>

</table>
</div>
<p style="margin: 8px 0px;">This is an&nbsp;<em>order-0 Markov model</em>, which predicts that each character occurs with a fixed probability, independent of previous characters. We're getting somewhere, but most events occur in context. Imagine randomly generating a year's worth of Fahrenheit temperature data. A series of 365 random integers between 0 and 100 wouldn't fool the average observer. It would be more credible to make today's temperature a random function of yesterday's temperature. If it is 85 degrees today, it is unlikely to be 15 degrees tomorrow. The same is true of English words: If this letter is a&nbsp;<q style="font-family: monospace;">q</q>, then the following letter is quite likely to be a&nbsp;<q style="font-family: monospace;">u</q>. You could generate more realistic random text by choosing each character from the ones likely to follow its predecessor. For this, process the input and build an order-1 model that determines the probability with which each character follows another character. It turns out that&nbsp;<q style="font-family: monospace;">s</q>&nbsp;is much more likely to be followed by&nbsp;<q style="font-family: monospace;">t</q>&nbsp;than&nbsp;<q style="font-family: monospace;">y</q>&nbsp;and that&nbsp;<q style="font-family: monospace;">q</q>&nbsp;is almost always followed by&nbsp;<q style="font-family: monospace;">u</q>. You could now produce some randomly generated&nbsp;<em>Tom Sawyer</em>&nbsp;by picking a starting character and then choosing the character to follow according to the probabilities of what characters followed in the source text. Here's some output produced from an&nbsp;<em>order-1 model</em>:</p>
<div class="in" style="margin: 0px 0px 0px 16px;">

<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px; width: 989px;">

<tbody>

<tr style="border-collapse: collapse;">
<td width="80" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);">Order 1</td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);"><blockquote style="font-family: monospace; margin: 0px;">"Shand tucthiney m?" le ollds mind Theybooure He, he swhit Pereg lenigabo Jodind alllld ashanthe ainofevids trelin--p asto oun theanthadomoere</blockquote></td>
</tr>

</tbody>

</table>
</div>
<p style="margin: 8px 0px;">This idea extends to longer sequences of characters. An order-2 model generates each character as a function of the two-character sequence preceding it. In English, the sequence&nbsp;<q style="font-family: monospace;">sh</q>&nbsp;is typically followed by the vowels, less frequently by&nbsp;<q style="font-family: monospace;">r</q>&nbsp;and&nbsp;<q style="font-family: monospace;">w</q>, and rarely by other letters. An order-5 analysis of&nbsp;<em>Tom Sawyer</em>&nbsp;reveals that&nbsp;<q style="font-family: monospace;">leave</q>&nbsp;is often followed by&nbsp;<q style="font-family: monospace;">s</q>&nbsp;or space but never&nbsp;<q style="font-family: monospace;">j</q>or&nbsp;<q style="font-family: monospace;">q</q>, and that&nbsp;<q style="font-family: monospace;">Sawye</q>&nbsp;is always followed by&nbsp;<q style="font-family: monospace;">r</q>. Using an order-<em>k</em>&nbsp;model, you generate random output by choosing the next character based on the probabilities of what followed the previous&nbsp;<em>k</em>&nbsp;characters in the input text. This string of characters preceding the current point is called the seed.</p>
<p style="margin: 8px 0px;">At only a moderate level of analysis (say, orders 5 to 7), the randomly generated text begins to take on many of the characteristics of the source text. It probably won't make complete sense, but you'll be able to tell that it was derived from&nbsp;<em>Tom Sawyer</em>&nbsp;as opposed to, say, Pride and Prejudice. At even higher levels, the generated words tend to be valid and the sentences start to scan. Here are some more examples:</p>
<div class="in" style="margin: 0px 0px 0px 16px;">

<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px; width: 989px;">

<tbody>

<tr style="border-collapse: collapse;">
<td width="80" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);">Order 2</td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);"><blockquote style="font-family: monospace; margin: 0px;">"Yess been." for gothin, Tome oso; ing, in to weliss of an'te cle -- armit. Papper a comeasione, and smomenty, fropeck hinticer, sid, a was Tom, be suck tied. He sis tred a youck to themen</blockquote></td>
</tr>

</tbody>

</table>
</div>
<div class="in" style="margin: 0px 0px 0px 16px;">

<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px; width: 989px;">

<tbody>

<tr style="border-collapse: collapse;">
<td width="80" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);">Order 4</td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);"><blockquote style="font-family: monospace; margin: 0px;">en themself, Mr. Welshman, but him awoke, the balmy shore. I'll give him that he couple overy because in the slated snufflindeed structure's kind was rath. She said that the wound the door a fever eyes that WITH him.</blockquote></td>
</tr>

</tbody>

</table>
</div>
<div class="in" style="margin: 0px 0px 0px 16px;">

<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px; width: 989px;">

<tbody>

<tr style="border-collapse: collapse;">
<td width="80" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);">Order 6</td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);"><blockquote style="font-family: monospace; margin: 0px;">Come -- didn't stand it better judgment; His hands and bury it again, tramped herself! She'd never would be. He found her spite of anything the one was a prime feature sunset, and hit upon that of the forever.</blockquote></td>
</tr>

</tbody>

</table>
</div>
<div class="in" style="margin: 0px 0px 0px 16px;">

<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px; width: 989px;">

<tbody>

<tr style="border-collapse: collapse;">
<td width="80" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);">Order 8</td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);"><blockquote style="font-family: monospace; margin: 0px;">look-a-here -- I told you before, Joe. I've heard a pin drop. The stillness was complete, how- ever, this is awful crime, beyond the village was sufficient. He would be a good enough to get that night, Tom and Becky.</blockquote></td>
</tr>

</tbody>

</table>
</div>
<div class="in" style="margin: 0px 0px 0px 16px;">

<table style="border-collapse: collapse; border-color: rgb(51, 51, 51); border-style: solid; border-width: 1px 0px; width: 989px;">

<tbody>

<tr style="border-collapse: collapse;">
<td width="80" style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 1px 1px 0px; border-style: solid solid solid none; border-top-color: rgb(51, 51, 51); border-right-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51);">Order 10</td>
<td style="border-collapse: collapse; padding: 2px 16px; border-width: 1px 0px 1px 1px; border-style: solid none solid solid; border-top-color: rgb(51, 51, 51); border-bottom-color: rgb(51, 51, 51); border-left-color: rgb(51, 51, 51);"><blockquote style="font-family: monospace; margin: 0px;">you understanding that they don't come around in the cave should get the word "beauteous" was over-fondled, and that together" and decided that he might as we used to do -- it's nobby fun. I'll learn you."</blockquote></td>
</tr>

</tbody>

</table>
</div>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Hints</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Although it may sound daunting at first glance, this task is supremely manageable with the bag of power tools you bring to the job site.</p>
<p style="margin: 8px 0px;"><code>Map</code>&nbsp;and&nbsp;<code>Vector</code>&nbsp;are just what you need to store the model information. The keys into the map are the possible seeds (e.g., if the order is 2, each key is a 2-character sequence found in the source text). The associated value is a vector of all the characters that follow that seed in the source text. That vector can - and likely will - contain a lot of duplicate entries. Duplicates represent higher probability transitions from this Markov state. Explicitly storing duplicates is the easiest strategy and makes it simple to choose a random character from the correct frequency distribution. A more space-efficient strategy would store each character at most once, with its frequency count. However, it's a bit more awkward to code this way. You are welcome to do either, but if you choose the latter, please take extra care to keep the code clean.</p>
<p style="margin: 8px 0px;">Determining which seed(s) occurs most frequently in the source can be done by iterating over the entries once you have finished the analysis.</p>
<p style="margin: 8px 0px;">To read a file one character at a time, you can use the&nbsp;<code>get</code>&nbsp;member function for&nbsp;<code>ifstream</code>&nbsp;like this:</p>
<code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">
<pre style="padding: 0px; margin-top: 0px; margin-bottom: 0px;"><strong>char</strong> ch;
<strong>while</strong> (input.get(ch)) {
    <em>/* ... process ch ... */</em>
}</pre>
</code>
<p style="margin: 8px 0px;">This will read the file one character at a time, executing the loop until no more characters can be read.</p>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">Possible extensions</h5>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">There are many extensions you could think about introducing into the random writer program - most of which will also make it easier for you to generate a contest entry. One possibility is to extend the Markov model so that the individual units are words rather than characters. Another is to write a program that runs the Markov model in the opposite direction, in which the goal is to recognize an author by his or her characteristic patterns. This requires building multiple Markov models, one for each candidate author, and comparing them to an unattributed text to find the best match. This sort of "literary forensic analysis" has been used to try to determine the correct attribution for texts where the authorship is unknown or disputed.</p>
</div>
<h5 style="padding: 0px; margin: 0px; font-size: 18px; line-height: 20px;">References</h5>
<div class="in" style="margin: 0px 0px 0px 16px;"><ol class="tl">
<li>Dewdney A. A potpourri of programmed prose and prosody [J]. Scientific American, 1989.</li>
<li>Shannon C E. A mathematical theory of communication [J]. ACM SIGMOBILE Mobile Computing and Communications Review, 2001, 5(1): 3-55.</li>
<li>Markov chain [EB/OL]. [2013-09-14]. http://en.wikipedia.org/wiki/Markov_chain</li>
<li>Free ebooks - Project Gutenberg [G/OL]. [2013-09-14]. http://www.gutenberg.org</li>
</ol></div>
</div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Hand in</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">You only need to turn in your&nbsp;<code>WordLadder.cpp</code>&nbsp;and&nbsp;<code>RandomWriter.cpp</code>&nbsp;files.</p>
<p style="margin: 8px 0px;">Upload your code as a gzipped tar file to&nbsp;<a href="ftp://azard5:public@public.sjtu.edu.cn/upload/lab1/" target="_blank" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">ftp://azard5:public@public.sjtu.edu.cn/upload/lab1/</a><br></p>
<p style="margin: 8px 0px;">example filename: 5130379001_lab1.tar.gz</p>
<p style="margin: 8px 0px;">If you have any question or find some bugs, please contact&nbsp;<a href="mailto:wxdwfc@sjtu.edu.cn" style="color: rgb(34, 102, 187); font-weight: bold; text-decoration: none; outline-style: none;">wxdwfc@sjtu.edu.cn</a></p>
</div>
<time datetime="2014-09-22T23:00:00+08:00" class="assigned_time" style="text-align: right; display: block;">2014-09-22</time><time datetime="2014-09-22T23:00:00+08:00" class="assigned_time" style="text-align: right; display: block;">
<h3 style="padding: 0px; margin: 24px 0px 8px; font-size: 24px; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(170, 170, 170); font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; text-align: start;">Lab 1 Test Case</h3>
<div class="in" style="margin: 0px 0px 0px 16px; font-family: 'Heiti SC', 黑体-简, 'MS Yahei', 微软雅黑, STXihei, 华文细黑, 'WenQuanYi ZenHei', 文泉驿正黑体, Sans-sarif; line-height: normal; text-align: start;">
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Problem I: Word ladders</h4>
<div class="in" style="margin: 0px 0px 0px 16px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">some none<br>none some<br>some once<br>once some<br>some none<br>none once<br>work play<br>play work<br>sleep awake<br>awake sleep</code></div>
<h4 style="padding: 0px; margin: 6px 0px; font-size: 20px; line-height: 20px;">Problem II: Random Writer</h4>
<div class="in" style="margin: 0px 0px 0px 16px;">
<p style="margin: 8px 0px;">Order = 3</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">abcdefghijklmnoqprstuvwxyz<br>abcdefghijklmnoqprstuvwxyz</code></p>
<p style="margin: 8px 0px;">Order = 3</p>
<p style="margin: 8px 0px;"><code class="codep" style="border: 1px dashed rgb(170, 170, 170); display: block; margin: 8px 32px;">aaaaaaaaaaaxaaaaaaaaaaaax<br>bcdbcdbcdbcdbcdbcdbcdbcde</code></p>
</div>
</div>
</time></div>
</div>

