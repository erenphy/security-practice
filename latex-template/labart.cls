\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{labart}[2020 08]

\LoadClass[a4paper]{article}

\newif\iflangcn
\newif\iflangen

\DeclareOption{cn}{\langcntrue}
\DeclareOption{en}{\langentrue}
\ProcessOptions\relax

\RequirePackage[UTF8]{ctex}
\RequirePackage{CJKutf8}

\RequirePackage{amsmath}
\RequirePackage{booktabs}
\RequirePackage{caption}
\RequirePackage{graphicx}
\RequirePackage{setspace}
\RequirePackage{subfigure}
\RequirePackage{titlesec}
\RequirePackage{titletoc}
\RequirePackage{ulem}
\RequirePackage{multirow}
\RequirePackage{indentfirst}
\RequirePackage{float}
% url
\RequirePackage{url}
\RequirePackage{setspace}
% itemize
\RequirePackage{enumitem}


% 页边距设置
\RequirePackage{geometry}
% \linespread{1.35}
% 调整页边距
\geometry{top=1.5cm,bottom=1.5cm,left=2cm,right=2cm} 

\newcommand*{\labtitle}[1]{
  \def\@labtitle{#1}
}


\RequirePackage{fancyhdr}
\pagestyle{fancy}

% \makeatletter
\lhead{}
\rhead{}
\chead{\small{\@labtitle}} % 页眉
% \fancyhead[C]{\@title}

% \makeatother


% 代码样式
\RequirePackage{listings}
\RequirePackage{xcolor}

\lstset{
 columns            = fixed,                                    % flexible / fixed 固定字符宽度
 basicstyle         = \small\ttfamily,                          % 基本格式
 numbers            = left,                                     % 在左侧显示行号
 numberstyle        = \footnotesize\color{darkgray},            % 设定行号格式
 keywordstyle       = \color[RGB]{40,40,255},                   % 设定关键字颜色
 tabsize            = 2,                                        % 缩进长度
 commentstyle       = \color{olive}\scshape,                    % 设置代码注释的格式
 stringstyle        = \color{purple},                           % 设置字符串格式
 showstringspaces   = false,                                    % 不显示字符串中的空格
 language           = c++,                                      % 设置语言
 breaklines         = true,                                     % 代码过长则换行
 xleftmargin        = 20pt,                                     % 代码左边距
 xrightmargin       = 0pt,                                      % 代码右边距
 frame              = tb,                                       % 方框框住代码 box / none 不显示背景边框
 framesep           = \fboxsep,
 framexleftmargin   = 20pt,                                     % 代码框左边距
}

% [x64]{Assembler} define
\lstdefinelanguage
   [x64]{Assembler}     % add a "x64" dialect of Assembler
   [x86masm]{Assembler} % based on the "x86masm" dialect
   % with these extra keywords:
   {morekeywords={CDQE,CQO,CMPSQ,CMPXCHG16B,JRCXZ,LODSQ,MOVSXD, %
                  POPFQ,PUSHFQ,SCASQ,STOSQ,IRETQ,RDTSCP,SWAPGS, %
                  rax,rdx,rcx,rbx,rsi,rdi,rsp,rbp, %
                  r8,r8d,r8w,r8b,r9,r9d,r9w,r9b, %
                  r10,r10d,r10w,r10b,r11,r11d,r11w,r11b, %
                  r12,r12d,r12w,r12b,r13,r13d,r13w,r13b, %
                  r14,r14d,r14w,r14b,r15,r15d,r15w,r15b}} % etc.

\lstset{language=[x64]Assembler}
