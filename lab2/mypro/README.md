
<h1 id="lab2" style="box-sizing: border-box; font-size: 2.6em; margin: 1.8em 0px; font-family: 'Source Sans Pro', sans-serif; font-weight: 300; line-height: 1.1; color: rgb(63, 63, 63); outline: none !important; background-color: rgb(246, 246, 246);">Lab2</h1>
<hr style="box-sizing: content-box; height: 0px; margin: 2em 0px; border-right-width: 0px; border-bottom-width: 0px; border-left-width: 0px; border-top-style: solid; border-top-color: rgba(128, 128, 128, 0.0980392); color: rgb(63, 63, 63); font-family: 'Source Sans Pro', sans-serif; font-size: 18px; line-height: 26.1000003814697px; text-align: justify; outline: none !important; background-color: rgb(246, 246, 246);">

<table style="box-sizing: border-box; border-collapse: collapse; border-spacing: 0px; max-width: 100%; margin-bottom: 20px; color: rgb(63, 63, 63); font-family: 'Source Sans Pro', sans-serif; font-size: 18px; line-height: 26.1000003814697px; text-align: justify; outline: none !important; background-color: rgb(246, 246, 246);">
<thead style="box-sizing: border-box; outline: none !important;">



<tr style="box-sizing: border-box; outline: none !important;">
<th style="box-sizing: border-box; text-align: left; padding: 8px; line-height: 20px; vertical-align: bottom; border-top-width: 0px; outline: none !important;">文件</th><th style="box-sizing: border-box; text-align: left; padding: 8px; line-height: 20px; vertical-align: bottom; border-top-width: 0px; outline: none !important;"><font color="#000000">说明</font></th>



</tr>
</thead>



<tbody style="box-sizing: border-box; outline: none !important;">

<tr style="box-sizing: border-box; outline: none !important;">
<td style="box-sizing: border-box; outline: none !important; padding: 8px; line-height: 20px; vertical-align: top; border-top-width: 1px; border-top-style: solid; border-top-color: rgb(221, 221, 221);">city_2.3.cpp</td>
<td style="box-sizing: border-box; outline: none !important; padding: 8px; line-height: 20px; vertical-align: top; border-top-width: 1px; border-top-style: solid; border-top-color: rgb(221, 221, 221);">暴力搜索+平均期望值2.3剪枝+无末尾处理</td>
</tr>

<tr style="box-sizing: border-box; outline: none !important;">
<td style="box-sizing: border-box; outline: none !important; padding: 8px; line-height: 20px; vertical-align: top; border-top-width: 1px; border-top-style: solid; border-top-color: rgb(221, 221, 221);">city_ctdp.cpp</td>
<td style="box-sizing: border-box; outline: none !important; padding: 8px; line-height: 20px; vertical-align: top; border-top-width: 1px; border-top-style: solid; border-top-color: rgb(221, 221, 221);">记录方案插头dp</td>
</tr>

<tr style="box-sizing: border-box; outline: none !important;">
<td style="box-sizing: border-box; outline: none !important; padding: 8px; line-height: 20px; vertical-align: top; border-top-width: 1px; border-top-style: solid; border-top-color: rgb(221, 221, 221);">city_ctdp_nopath.cpp</td>
<td style="box-sizing: border-box; outline: none !important; padding: 8px; line-height: 20px; vertical-align: top; border-top-width: 1px; border-top-style: solid; border-top-color: rgb(221, 221, 221);">不记录方案的插头dp[记录方案部分我写的效率较低 此代码比上一个快很多倍]</td>
</tr>

</tbody>

</table>

<hr style="box-sizing: content-box; height: 0px; margin: 2em 0px; border-right-width: 0px; border-bottom-width: 0px; border-left-width: 0px; border-top-style: solid; border-top-color: rgba(128, 128, 128, 0.0980392); color: rgb(63, 63, 63); font-family: 'Source Sans Pro', sans-serif; font-size: 18px; line-height: 26.1000003814697px; text-align: justify; outline: none !important; background-color: rgb(246, 246, 246);">
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">(</span><span style="font-family:宋体;
mso-ascii-font-family:Calibri;mso-ascii-theme-font:minor-latin;mso-fareast-font-family:
宋体;mso-fareast-theme-font:minor-fareast;mso-hansi-font-family:Calibri;
mso-hansi-theme-font:minor-latin">期间有运行其它程序所以时间不是很稳定</span><span lang="EN-US">)<o:p></o:p></span></p>
<table class="MsoTableGrid" border="1" cellspacing="0" cellpadding="0" style="border-collapse:collapse;border:none;mso-border-alt:solid windowtext .5pt;
 mso-yfti-tbllook:1184;mso-padding-alt:0cm 5.4pt 0cm 5.4pt">

<tbody>

<tr>
<td width="284" valign="top" style="width:213.05pt;border:solid windowtext 1.0pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
<p class="MsoNormal"><span style="font-family:宋体;mso-ascii-font-family:Calibri;
  mso-ascii-theme-font:minor-latin;mso-fareast-font-family:宋体;mso-fareast-theme-font:
  minor-fareast;mso-hansi-font-family:Calibri;mso-hansi-theme-font:minor-latin">以平均期望值</span><span lang="EN-US">2.3</span><span style="font-family:宋体;mso-ascii-font-family:Calibri;
  mso-ascii-theme-font:minor-latin;mso-fareast-font-family:宋体;mso-fareast-theme-font:
  minor-fareast;mso-hansi-font-family:Calibri;mso-hansi-theme-font:minor-latin">剪枝得到的结果：</span>
  <span lang="EN-US"><o:p></o:p></span></p>
</td>
<td width="284" valign="top" style="width:213.05pt;border:solid windowtext 1.0pt;
  border-left:none;mso-border-left-alt:solid windowtext .5pt;mso-border-alt:
  solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
<p class="MsoNormal"><span style="font-family:宋体;mso-ascii-font-family:Calibri;
  mso-ascii-theme-font:minor-latin;mso-fareast-font-family:宋体;mso-fareast-theme-font:
  minor-fareast;mso-hansi-font-family:Calibri;mso-hansi-theme-font:minor-latin">以下为插头</span><span lang="EN-US">dp</span><span style="font-family:宋体;mso-ascii-font-family:Calibri;
  mso-ascii-theme-font:minor-latin;mso-fareast-font-family:宋体;mso-fareast-theme-font:
  minor-fareast;mso-hansi-font-family:Calibri;mso-hansi-theme-font:minor-latin">得到的结果：</span>
  <span lang="EN-US"><o:p></o:p></span></p>
</td>
</tr>

<tr>
<td width="284" valign="top" style="width:213.05pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  padding:0cm 5.4pt 0cm 5.4pt">
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:1 ave:1<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:3 ave:1.5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:5 ave:1.66667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 4<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:7 ave:1.75<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:9 ave:1.8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:11 ave:1.83333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:13 ave:1.85714<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:15 ave:1.875<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 3 2 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:17 ave:1.88889<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 1 3 2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:19 ave:1.9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 3 2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:21 ave:1.90909<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:7 ave:1.75<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:12 ave:2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 4<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:16 ave:2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:21 ave:2.1<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:25 ave:2.08333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:30 ave:2.14286<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.002 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:34 ave:2.125<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.003 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:39 ave:2.16667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.013 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 2 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:43 ave:2.15<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.019 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:48 ave:2.18182<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:19 ave:2.11111<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 4<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:25 ave:2.08333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:32 ave:2.13333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:39 ave:2.16667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:46 ave:2.19048<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.015 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 1 2 3 3 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 2 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:52 ave:2.16667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.032 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 1 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:59 ave:2.18519<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.065 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 2 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:66 ave:2.2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.12 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 1 2 3 3 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:73 ave:2.21212<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 4<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:36 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.003 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:43 ave:2.15<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.011 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 1 2 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:52 ave:2.16667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.006 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:63 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.023 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:72 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.111 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 2 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:80 ave:2.22222<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.635 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 1 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:90 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:1.326 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:99 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.003 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:55 ave:2.2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.028 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:67 ave:2.23333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.027 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:79 ave:2.25714<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.287 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 1 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:89 ave:2.225<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.244 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 3 3 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:101 ave:2.24444<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:2.725 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 2 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:112 ave:2.24<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:5.78 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 2 1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 1 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:124 ave:2.25455<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.023 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:80 ave:2.22222<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.261 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:94 ave:2.2381<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.294 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:108 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.703 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:122 ave:2.25926<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:5.724 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 1 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 2 3 1 3 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 1 3 2 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:135 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:42.071 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:149 ave:2.25758<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.043 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:111 ave:2.26531<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.126 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:127 ave:2.26786<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:2.438 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 1 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:142 ave:2.25397<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:4.719 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 1 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:159 ave:2.27143<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:4.188 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 3 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 2 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 3 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 3 1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 3 2 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 3 2 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:175 ave:2.27273<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:1.775 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">8 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:145 ave:2.26563<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:3.693 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">8 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 2 1 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 3 2 1 3 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2 1 3 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:163 ave:2.26389<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:9.594 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">8 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 3 1 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 3 2 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 3 2 3 1 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 3 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 1 3 2 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:182 ave:2.275<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US"><font color="#ff0000">use:122.424 s</font><o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">8 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 1 2 3 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 3 3 1 2 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 1 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 3 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 1 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 2 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 3 2 3 1 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 2 3 1 3 2 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:200 ave:2.27273<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:4.474 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">9 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 3 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 3 1 2 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:184 ave:2.2716<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:110.73 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">9 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 3 2 1 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 2 1 3 3 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 3 2 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 2 1 3 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 3 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 3 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:205 ave:2.27778<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:245.522 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">9 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 2 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 1 3 3 3 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 1 2 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:225 ave:2.27273<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:18.908 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">10 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 1 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 3 2 1 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 3 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:228 ave:2.28<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:51.197 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">10 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 3 1 3 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 2 1 3 2 3 3 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 1 3 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:251 ave:2.28182<o:p></o:p></span></p>
</td>
<td width="284" valign="top" style="width:213.05pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:1 ave:1<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:3 ave:1.5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:5 ave:1.66667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 4<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:7 ave:1.75<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:9 ave:1.8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:11 ave:1.83333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:13 ave:1.85714<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:15 ave:1.875<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 3 2 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:17 ave:1.88889<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 1 3 2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:19 ave:1.9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 1 3 2 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:21 ave:1.90909<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:7 ave:1.75<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:12 ave:2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 4<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:16 ave:2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:21 ave:2.1<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:25 ave:2.08333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:30 ave:2.14286<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:34 ave:2.125<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:39 ave:2.16667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:43 ave:2.15<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:48 ave:2.18182<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:19 ave:2.11111<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 4<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:25 ave:2.08333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:32 ave:2.13333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:39 ave:2.16667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 1 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:46 ave:2.19048<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:52 ave:2.16667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 1 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:59 ave:2.18519<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.002 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:66 ave:2.2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.001 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 1 2 3 3 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:73 ave:2.21212<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.002 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 4<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:36 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.003 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:43 ave:2.15<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.004 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:52 ave:2.16667<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.005 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:63 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.006 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:72 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.007 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 3 1 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:80 ave:2.22222<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.009 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 2 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 3 1 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:90 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.009 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">4 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 3 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 3 2 3 1 3 2 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:99 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.017 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 5<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:55 ave:2.2<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.024 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:67 ave:2.23333<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.029 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:79 ave:2.25714<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.036 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 1 2 3 3 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2 3 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:89 ave:2.225<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.041 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 3 3 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:101 ave:2.24444<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.05 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 3 1 3 2 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:112 ave:2.24<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.055 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">5 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:124 ave:2.25455<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.142 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 6<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:80 ave:2.22222<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.182 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:94 ave:2.2381<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.22 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:108 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.255 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:122 ave:2.25926<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.296 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 1 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:135 ave:2.25<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:0.364 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">6 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 2 3 1 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 3 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 2 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 3 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 2 1 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 1 3 3 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:149 ave:2.25758<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:1.121 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 7<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:111 ave:2.26531<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:1.33 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 2 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:127 ave:2.26786<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:1.551 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 3 3 1 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 3 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 2 3 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 1 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:143 ave:2.26984<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:2.006 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 2 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 2 3 3 1 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:159 ave:2.27143<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:1.986 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">7 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 3 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 3 2 3 1 3 2 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 2 3 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 3 2 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 1 3 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 3 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:175 ave:2.27273<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:8.541 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">8 8<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 3 3 2 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 1 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 3 2 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2 1 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:145 ave:2.26563<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:10.205 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">8 9<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 2 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 3 2 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 1 3 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 1 3 3 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 3 1 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 3 3 2 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 3 1 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:163 ave:2.26389<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US">use:10.618 s<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">8 10<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 2 3 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 3 1 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 2 3 3 3 1 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 1 2 3 3 3 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 3 1 2 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 1 2 3 3 3 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 3 3 1 2 3 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 3 1 2 3 1 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:182 ave:2.275<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US"><font color="#ff0000">use:11.712 s</font><o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">8 11<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 1 3 2 1 3 1 3 2 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 3 2 3 3 1 3 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 1 3 2 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 3 2 3 3 1 3 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 2 1 3 1 3 2 3 3 1 2 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">1 3 3 2 3 3 1 1 2 3 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">3 3 2 1 3 2 3 3 3 3 1 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">2 1 3 3 2 1 3 2 1 2 3 <o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">max_popu:200 ave:2.27273<o:p></o:p></span></p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
</td>
</tr>

</tbody>

</table>
<p style="box-sizing: border-box; margin: 0px 0px 1.1em; color: rgb(63, 63, 63); font-family: 'Source Sans Pro', sans-serif; font-size: 18px; line-height: 26.1000003814697px; text-align: justify; outline: none !important; background-color: rgb(246, 246, 246);">





</p>
<p class="MsoNormal"><span lang="EN-US">&nbsp;</span></p>
