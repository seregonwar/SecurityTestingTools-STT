__int64 __usercall sub_1CB@<rax>(__int64 a1@<rdi>, __int64 a2@<rsi>)
{
  int v2; // er11
  int v3; // er9
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v7; // rcx
  __int64 v8; // r10
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 v11; // rcx

  v2 = *(unsigned __int16 *)(a1 + 0x3C);
  v3 = 0;
  if ( !*(_WORD *)(a1 + 0x3C) )
    return 0i64;
  v4 = *(_QWORD *)(a1 + 0x28);
  if ( !v4 || (v5 = a1 + v4) == 0 )
    BUG();
  while ( 1 )
  {
    v7 = v5 + v3 * *(unsigned __int16 *)(a1 + 0x3A);
    if ( *(_DWORD *)(v7 + 4) == 9 )
    {
      v8 = 0i64;
      v9 = *(_QWORD *)(v7 + 0x20) / *(_QWORD *)(v7 + 0x38);
      while ( v9 != v8 )
      {
        v10 = 0x18 * v8 + a1 + *(_QWORD *)(v7 + 0x18);
        if ( *(_DWORD *)(v10 + 8) == 8 )
          *(_QWORD *)(a2 + *(_QWORD *)v10) = a2 + *(_QWORD *)(v10 + 0x10);
        ++v8;
      }
    }
    if ( v2 <= ++v3 )
      break;
    v11 = *(_QWORD *)(a1 + 0x28);
    if ( v11 )
    {
      v5 = a1 + v11;
      if ( a1 + v11 )
        continue;
    }
    else
    {
      BUG();
    }
  }
  return 0i64;
}