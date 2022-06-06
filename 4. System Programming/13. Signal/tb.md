| signal number | signal name | when this signal is raised                                         | whom this signal is sent to                   | default action         |
| ------------- | ----------- | ------------------------------------------------------------------ | --------------------------------------------- | ---------------------- |
| 1             | SIGHUP      | a session leader with a controlling terminal(e.g. shell) is killed | all foreground child processes of this leader | kill                   |
| 2             | SIGINT      | ^c                                                                 | foreground process                            | kill                   |
| .....         |             |                                                                    |                                               |                        |
| 9             | SIGKILL     | kill -9 1234                                                       | pid 1234                                      | kill with no exception |
| .......       |             |                                                                    |                                               |                        |
| 11            | SIGSEGV     | illegal access of memory                                           | the process who accessed illegal memory area  | kill                   |
| .....         |             |                                                                    |                                               |                        |
| 15            | SIGTERM     | kill 1234                                                          | pid 1234                                      | kill                   |
| ...           |             |                                                                    |                                               |                        |
| 17            | SIGCHLD     | child process is killed                                            | the parent process                            | ignore                 |
| .........     |             |                                                                    |                                               |                        |
| 20            | SIGTSTP     | ^z                                                                 | the currrent process                          | suspend                |
| 31            | SIGSYS      | bad system call                                                    | the process who called the system call        | kill                   |
