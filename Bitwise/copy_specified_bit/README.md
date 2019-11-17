# The comparison

## copy_specified_bit
```clike=
int copy_specified_bit (int a, int b, unsigned i_th)
{
	int a_i = ( a >> i_th ) & 0x1;
	int b_i = ( b >> i_th ) & 0x1;

	if (a_i != b_i)
		return (a ^= (0x1 << i_th));
	else
		return a;
}
```
```shell=
0000000000400590 <copy_specified_bit>:
  400590:       89 d1                   mov    %edx,%ecx
  400592:       89 f8                   mov    %edi,%eax
  400594:       d3 f8                   sar    %cl,%eax
  400596:       d3 fe                   sar    %cl,%esi
  400598:       83 e0 01                and    $0x1,%eax
  40059b:       83 e6 01                and    $0x1,%esi
  40059e:       39 f0                   cmp    %esi,%eax
  4005a0:       74 0e                   je     4005b0 <copy_specified_bit+0x20>
  4005a2:       b8 01 00 00 00          mov    $0x1,%eax
  4005a7:       d3 e0                   shl    %cl,%eax
  4005a9:       31 f8                   xor    %edi,%eax
  4005ab:       c3                      retq
  4005ac:       0f 1f 40 00             nopl   0x0(%rax)
  4005b0:       89 f8                   mov    %edi,%eax
  4005b2:       c3                      retq
  4005b3:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  4005ba:       00 00 00
  4005bd:       0f 1f 00                nopl   (%rax)
```
## copy_specified_bit_optimized

```clike=
int copy_specified_bit_optimized (int a, int b, unsigned i_th)
{
	if ((a & (1 << i_th) >> i_th) & ((1 << i_th) >> i_th))
		return a;
	else
		return (a ^= (0x1 << i_th));
}
```

```shell=
00000000004005c0 <copy_specified_bit_optimized>:
  4005c0:       89 d1                   mov    %edx,%ecx
  4005c2:       41 b8 01 00 00 00       mov    $0x1,%r8d
  4005c8:       21 fe                   and    %edi,%esi
  4005ca:       41 d3 e0                shl    %cl,%r8d
  4005cd:       89 f8                   mov    %edi,%eax
  4005cf:       44 89 c2                mov    %r8d,%edx
  4005d2:       d3 fa                   sar    %cl,%edx
  4005d4:       85 f2                   test   %esi,%edx
  4005d6:       75 03                   jne    4005db <copy_specified_bit_optimized+0x1b>
  4005d8:       44 31 c0                xor    %r8d,%eax
  4005db:       f3 c3                   repz retq
  4005dd:       0f 1f 00                nopl   (%rax)
```
