// Ascii conversion 


Single digit int to char --> 9 + '0' = '9'    ,   will not work for more than 1 digit int --> 12 + '0' = <  and is != '12'
             char to int --> '9' - '0' =9  

  string s="A";
  use, string ans= to_string(s);
char c=ans[0];
