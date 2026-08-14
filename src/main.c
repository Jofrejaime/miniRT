#include "minirt.h"
#include "parser.h"
#include "errors.h"
#include "cleanup.h"
#include "debug.h"

int main(int argc, char **argv)
{
    t_rt   rt;
    int    fd;
    t_error err;
    t_token *tokens;

    ft_bzero(&rt, sizeof(t_rt)); 
    err = verify_args(argc, argv);
    if (err)
    {
        set_error(
            &rt.error,
            err,
            0,
            NULL,
            NULL,
            NULL);
        print_error(&rt.error);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        set_error(
            &rt.error,
            ERR_FILE_OPEN,
            0,
            NULL,
            argv[1],
            "Cannot open file");
        print_error(&rt.error);
        return (1);
    }
    tokens = tokenize(fd);
    close(fd);
    err = parse_scene(&rt, tokens);
    destroy_tokens(tokens);
    if (err)
    {
        print_error(&rt.error);
        scene_destroy(&rt.scene);
        return (1);
    }
    debug_rt(&rt);
    if (windows_ini(&rt.mlx, 400, 400, &rt) != 0)
    {
        scene_destroy(&rt.scene);
        return (1);
    }

  //  mlx_loop(rt.mlx.mlx);

    rt_destroy(&rt);

    return (0);
}