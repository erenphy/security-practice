#include<unistd.h>
#include<seccomp.h>
#include<sys/syscall.h>

int main()
{
    scmp_filter_ctx ctx;
    ctx = seccomp_init(SCMP_ACT_KILL); 
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0); 
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0); 
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0); 
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0); 
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0); 
    seccomp_load(ctx);

    char buff[100];
    read(0,buff,10);
    write(1,buff,10);
    
    seccomp_release(ctx);

    return 0;
}



