#include "../simple_shell.h"

/**
 * builtins - Stores information about builtin utilities
 * @dump: dump/print enviroment utility
 *
 */
struct builtin_s builtins[] = {
	{"env", env	},
	/* {"exit", exit	}, */
	/* {"cd", cd		}, */
	/* {"setenv" setenv	}, */
	/* {"unsetenv" unsetenv	}, */
	/* {"alias" alias	}, */
};


int builtins_count = sizeof(builtins) / sizeof(struct builtin_s);
