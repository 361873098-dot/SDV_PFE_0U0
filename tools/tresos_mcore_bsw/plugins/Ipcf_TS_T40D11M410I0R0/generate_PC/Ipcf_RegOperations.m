[!NOCODE!]

[!MACRO "GenerateUniqueElements", "ListWithDuplicateElements"!][!//
    [!VAR "ListWithUniqueElements" = "''"!][!//
    [!FOR "index" = "0" TO "num:i(count(text:split($ListWithDuplicateElements)))"!][!//
        [!IF "not(text:contains(text:split($ListWithUniqueElements), text:split($ListWithDuplicateElements)[$index + 1]))"!][!//
            [!VAR "ListWithUniqueElements" = "concat($ListWithUniqueElements, ' ', text:split($ListWithDuplicateElements)[$index + 1])"!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
    [!"$ListWithUniqueElements"!][!//
[!ENDMACRO!][!//

[!ENDNOCODE!]


[!NOCODE!]

[!MACRO "CountUnmanagedChannels"!][!//
	[!VAR "UnmanagedChannelCount" = "count(IpcfGlobalConfig/IpcfInstance/*/UnmanagedChannel/*)"!][!//
	[!"$UnmanagedChannelCount"!][!//
[!ENDMACRO!][!//


[!ENDNOCODE!]
