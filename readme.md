没错又双叒叕是BiTree
这次有点新的想法

就是将node的访问操作抽象出来
这样BiTree和CompleteBiTree的访问就可以统一起来了

而且模仿stl_allocator那样
也可以用模板实现node的多态
比如在BiTree中，就无需node有height属性
而在AVLtree中，有height属性的node就要好一些

相当于再设计一次tree吧，不晓得设计了几回了都还是不满意