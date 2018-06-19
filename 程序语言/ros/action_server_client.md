# action_server_client

##  action server client 与 server-client的不同之处

同样是点对点的通信模式，如果对于某项任务需要服务端处理较长时间，而客户端就需要等待同样时间，而不能处理其他任务。

In any large ROS-based system, there are cases when someone would like to send a request to a node to perform some task, and also receive a reply to the request. This can currently be achieved via ROS services.

In some cases, however, if the service takes a long time to execute, the user might want the ability to cancel the request during execution or get periodic feedback about how the request is progressing. The actionlib package provides tools to create servers that execute long-running goals that can be preempted. It also provides a client interface in order to send requests to the server.



## action message 的格式

```
#goal definition
#the lines with the hash signs are merely comments
#goal, result and feedback are defined by this fixed order, and separated by 3 hyphens
int32 input
---
#result definition
int32 output
int32 goal_stamp
---
#feedback
int32 fdbk
```





