If you have a file called `file.txt` that you are requesting, then the unencrypted message should look like this:

```
┌───────────────────────────────────────────────────────────────────────────────┐
│0xae     // map tag                                                            │
│0x01     // 1 kv pair                                                          │
├───────────────────────────────────────────────────────┬───────────┬───────────┤
│0xaa     // string8 tag                                │           │           │
│0x07     // 7 characters                               │ key       │           │
│Request  // the string "Request"                       │           │           │
├───────────────────────────────────────────────────────┼───────────┤  pair 1   │
│0xae     // the value associated with the key is a map │           │           │
│0x01     // 1 kv pair                                  │           │           │
├──────────────────────────────┬───────────┬────────────┤           │           │
│0xaa     // string8 tag       │           │            │           │           │
│0x04     // 4 characters      │ key       │            │ value     │           │
│name     // the string "name" │           │            │           │           │
├──────────────────────────────┼───────────┤ pair 1     │           │           │
│0xaa     // string8 tag       │           │            │           │           │
│0x08     // 8 characters      │ value     │            │           │           │
│file.txt // the filename      │           │            │           │           │
└──────────────────────────────┴───────────┴────────────┴───────────┴───────────┘           
```

In decimal:
```
[174, 1, 170, 7, 82, 101, 113, 117, 101, 115, 116, 174, 1, 170, 4, 110, 97, 109, 101, 170, 8, 102, 105, 108, 101, 46, 116, 120, 116]
```
In hex:
```
[0xAE, 0x01, 0xAA, 0x07, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0xAE, 0x01, 0xAA, 0x04, 0x6E, 0x61, 0x6D, 0x65, 0xAA, 0x08, 0x66, 0x69, 0x6C, 0x65, 0x2E, 0x74, 0x78, 0x74]
```