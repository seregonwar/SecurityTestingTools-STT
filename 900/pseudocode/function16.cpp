__int64 __usercall sub_26E(__int64 a1, unsigned __int64 a2, __int64 a3, __int64 a4, _QWORD *a5)
{
  __int64 result; // rax
  __int64 v9; // rcx
  __int64 v10; // rcx
  int v11; // er8
  int v12; // er8
  unsigned __int64 v13[6]; // [rsp+0h] [rbp-30h] BYREF

  if ( !a3 )
    return 1i64;
  if ( !a1 || !a4 || !a2 || (unsigned int)MEMORY[0x45168](a2, 4i64) || (*(_WORD *)(a3 + 0x10) & 0xFFFD) != 1 )
    return 1i64;
  v11 = sub_5(a1, a3, a5);
  if (v11 || *a5 <= a2)
  {
    v12 = sub_C8(a1, a3);
    if (v12)
    {
      return 3i64;
    }
    int result = sub_1CB(a3, a1);
    if (result)
    {
      return 4i64;
    }
    if (a5)
    {
      *a5 = *(_QWORD *)(a3 + 0x18) + a1;
    }
    return result;
  }
  return 2i64;
}