

org 100h

.data 
    a db "enter the 1st nunber:$"
    b db "enter the 2nd number:$"
    c db "result$"
    
.code
main:
    mov ax, @data
    mov ds, ax
    
    lea dx, a
    mov ah, 09h
    int 21h
    
    mov ah, 01h
    int 21h
    mov bl, al
    
    lea dx, b
    mov ah, 09h
    int 21h
    
    mov ah, 01h
    int 21h
    mov bh, al
    
    
    mov bh, 30h
    int 21h
    mov bh, al
    
    sub bh, 30h
    sub bl, 30h
    
    lea dx, c
    mov ah, 09h
    int 21h
    
    
    mov dl, bh
    mov ah, 02h
    int 21h
    
    mov ax, 4C00h
    int 21h
    
ret