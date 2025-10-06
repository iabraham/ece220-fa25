### README

The file c2lc3.md in this folder lays out step by step how to do stack build
up and tear down across function calls. 

The file `running.asm` in this folder shows the implementation of a small
recursive function in LC3, in great detail. 

```
int running_sum(int n){
    int fn;
    if (n==1)
    fn = 1;
    else
    fn = n + running_sum(n-1);
    return fn;
}

int main(void){
    int n = 4;
    running_sum(n);
}
```
