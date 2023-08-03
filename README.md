欢迎使用圣遗物分析助手Relic Analyse Assistance(RAA)
根据指引，你可以使用RAA对圣遗物进行分析
你也可以将json文件作为参数在命令行传入以简化操作，例：
.\raa.exe .\mona.json

关于圣遗物显示：
RAA提供两种显示圣遗物的方式，详细模式和缩略模式
在详细模式下，圣遗物主属性和副属性各占一行，副属性的开头添加了两个空格用于区分，不同圣遗物间用空行隔开。
在缩略模式下，每个圣遗物仅占一行，主属性紧跟在圣遗物等级之后，副属性和主属性间添加了"  ||  "用于区分。

使用YAS导出的json文件工作
地址：https://github.com/wormtql/yas/releases
使用cjson库对json进行处理
地址：https://github.com/DaveGamble/cJSON

圣遗物数组的最后一个圣遗物后的一个setname被设置为"end"用于表示结尾
最后一个副词条后的词条名也被设置为"end"(如果副词条满四个则没有这一部分)
