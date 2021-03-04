# uls

### Installation:
>**1. git clone  https://github.com/nnocturnnn/uls.git
>**2. cd uls
>**3. make
```
./uls -z |cat-e
uls: illegal option -- z
usage: uls [-lRGAaTh@eLouingr1Cmp] [file ...]
```

```
>./uls -l |cat-e
total 0
drwxr-xr-x  4 neo  staff  128 May 17 15:15 dir1$
drwxr-xr-x  2 neo  staff   64 May 17 14:57 dir2$
drwxr-xr-x  2 neo  staff   64 May 17 14:57 dir3$
```
### Flags-table:

| Flag |                         Description                        |
|:----:|:----------------------------------------------------------:|
|   l  | List in long format                                        |
|   R  | Recursively list subdirectories encountered                |
|   G  | Enable colorized output                                    |
|   A  | List all entries except for . and ..                       |
|   a  | Include directory entries whose names begin with a dot     |
|   T  | Display full time                                          |
|   h  | list long format with readable file size                   |
|   @  | Display extended attribute keys and sizes in long (-l) out |
|   e  | Print the Access Control List                              |
|   L  | Follow all symbolic links                                  |
|   o  | Suppressed group                                           |
|   u  | Use time of last access                                    |
|   i  | For each file, print the file's file serial number         |
|   n  | Display user and group IDs                                 |
|   g  | Suppressed owner name                                      |
|   r  | Reverse the order of the sort                              |
|   1  | Force output to be one entry per line                      |
|   C  |  Force multi-column output                                 |
|   m  | Stream output format; list files across the page           |
|   p  | Force output to be one entry per line                      |
|:----:|:----------------------------------------------------------:|
