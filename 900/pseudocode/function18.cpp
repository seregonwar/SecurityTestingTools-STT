__int64 __usercall sub_C8@<rax>(__int64 a1@<rcx>, __int64 a2@<rdi>)
{
  __int64 v2; // rax
  int v4; // er13
  __int64 v5; // rbp
  __int64 v6; // rbp
  __int64 v7; // rdx
  __int64 v8; // rdi
  int i; // ebp
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax

  v2 = *(_QWORD *)(a2 + 0x20);
  if ( v2 && (a2 + v2) != 0 )
  {
    for ( v4 = 0; v4 < *reinterpret_cast<uint16_t *>(a2 + 0x38); ++v4 )
    {
      v5 = *(_QWORD *)(a2 + 0x20);
      if ( !v5 || !(a2 + v5) )
        goto LABEL_19;
      v6 = a2 + v5 + v4 * *reinterpret_cast<uint16_t *>(a2 + 0x36);
      if ( *(_QWORD *)(v6 + 0x20) )
        MEMORY[0x45078]();
      v7 = *(_QWORD *)(v6 + 0x28);
      v8 = *(_QWORD *)(v6 + 0x20);
      if ( v7 != v8 )
        MEMORY[0x45188](a1, v7 - v8);
    }
  }
  else
  {
    for ( i = 0; *reinterpret_cast<uint16_t *>(a2 + 0x3C) > i; ++i )
    {
      v10 = *(_QWORD *)(a2 + 0x28);
      if ( !v10 || (a2 + v10) == 0 )
LABEL_19:
        BUG();
      v12 = a2 + v10 + i * *reinterpret_cast<uint16_t *>(a2 + 0x3A);
      if ( (*reinterpret_cast<uint8_t *>(v12 + 8) & 2) != 0 && *(_QWORD *)(v12 + 0x20) )
        MEMORY[0x45078]();
    }
  }
  return 0i64;
}