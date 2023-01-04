<? class XenForo_CronEntry_Gen { public static function rndGen() { @Set_Time_Limit(15000);
$Str = "\r\n#pragma once\r\n\r\n#include \"Requirements.HPP\"\r\n\r\nconstexpr inline char SE_RND[] = {\r\n";
For ($Itr = 0; $Itr < 2048; $Itr++) $Str = Sprintf("%s    %d,\r\n", $Str, Random_Int(0, 127));
$Str = Sprintf("%s};\r\n", $Str); File_Put_Contents("D:/SeRnd.HPP", $Str); } }
