cat > 0-whatsmyname.c << 'EOF'
#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    printf("%s\n", argv[0]);
    return (0);
}
EOF
