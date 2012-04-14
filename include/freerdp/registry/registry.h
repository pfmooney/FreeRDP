/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Portable Windows Registry Implementation
 *
 * Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_REGISTRY_H
#define FREERDP_REGISTRY_H

#include <freerdp/utils/windows.h>

#ifdef _WIN32

#include <winreg.h>

#else

#include <freerdp/wtypes.h>

#define WINAPI FREERDP_API

typedef HANDLE HKEY;
typedef HANDLE* PHKEY;

typedef DWORD ACCESS_MASK;
typedef ACCESS_MASK* PACCESS_MASK;

typedef ACCESS_MASK REGSAM;

#define HKEY_CLASSES_ROOT								0x80000000
#define HKEY_CURRENT_USER								0x80000001
#define HKEY_LOCAL_MACHINE								0x80000002
#define HKEY_USERS									0x80000003
#define HKEY_PERFORMANCE_DATA								0x80000004
#define HKEY_PERFORMANCE_TEXT								0x80000050
#define HKEY_PERFORMANCE_NLSTEXT							0x80000060
#define HKEY_CURRENT_CONFIG								0x80000005
#define HKEY_DYN_DATA									0x80000006
#define HKEY_CURRENT_USER_LOCAL_SETTINGS						0x80000007

#define RRF_RT_REG_NONE									0x00000001
#define RRF_RT_REG_SZ									0x00000002
#define RRF_RT_REG_EXPAND_SZ								0x00000004
#define RRF_RT_REG_BINARY								0x00000008
#define RRF_RT_REG_DWORD								0x00000010
#define RRF_RT_REG_MULTI_SZ								0x00000020
#define RRF_RT_REG_QWORD								0x00000040

#define RRF_RT_DWORD									(RRF_RT_REG_BINARY | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD									(RRF_RT_REG_BINARY | RRF_RT_REG_QWORD)
#define RRF_RT_ANY									0x0000FFFF

#define RRF_NOEXPAND									0x10000000
#define RRF_ZEROONFAILURE								0x20000000

typedef struct _SECURITY_ATTRIBUTES
{
	DWORD nLength;
	LPVOID lpSecurityDescriptor;
	BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

struct val_context
{
	int valuelen;
	LPVOID value_context;
	LPVOID val_buff_ptr;
};

typedef struct val_context *PVALCONTEXT;

typedef struct pvalueA
{
	LPSTR pv_valuename;
	int pv_valuelen;
	LPVOID pv_value_context;
	DWORD pv_type;
} PVALUEA, *PPVALUEA;

typedef struct pvalueW
{
	LPWSTR pv_valuename;
	int pv_valuelen;
	LPVOID pv_value_context;
	DWORD pv_type;
} PVALUEW, *PPVALUEW;

#ifdef UNICODE
typedef PVALUEW PVALUE;
typedef PPVALUEW PPVALUE;
#else
typedef PVALUEA PVALUE;
typedef PPVALUEA PPVALUE;
#endif

typedef struct value_entA
{
	LPSTR ve_valuename;
	DWORD ve_valuelen;
	DWORD_PTR ve_valueptr;
	DWORD ve_type;
} VALENTA, *PVALENTA;

typedef struct value_entW
{
	LPWSTR ve_valuename;
	DWORD ve_valuelen;
	DWORD_PTR ve_valueptr;
	DWORD ve_type;
} VALENTW, *PVALENTW;

#ifdef UNICODE
typedef VALENTW VALENT;
typedef PVALENTW PVALENT;
#else
typedef VALENTA VALENT;
typedef PVALENTA PVALENT;
#endif

LONG WINAPI RegCloseKey(HKEY hKey);

LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult);
LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName, HKEY hKey, PHKEY phkResult);

#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#else
#define RegConnectRegistry RegConnectRegistryA
#endif

LONG WINAPI RegCopyTreeW(HKEY hKeySrc, LPCWSTR lpSubKey, HKEY hKeyDest);
LONG WINAPI RegCopyTreeA(HKEY hKeySrc, LPCSTR lpSubKey, HKEY hKeyDest);

#ifdef UNICODE
#define RegCopyTree RegCopyTreeW
#else
#define RegCopyTree RegCopyTreeA
#endif

LONG WINAPI RegCreateKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions,
		REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
LONG WINAPI RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions,
		REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);

#ifdef UNICODE
#define RegCreateKeyEx RegCreateKeyExW
#else
#define RegCreateKeyEx RegCreateKeyExA
#endif

LONG WINAPI RegCreateKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass,
		DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter);
LONG WINAPI RegCreateKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass,
		DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter);

#ifdef UNICODE
#define RegCreateKeyTransacted RegCreateKeyTransactedW
#else
#define RegCreateKeyTransacted RegCreateKeyTransactedA
#endif

LONG WINAPI RegDeleteKeyW(HKEY hKey, LPCWSTR lpSubKey);
LONG WINAPI RegDeleteKeyA(HKEY hKey, LPCSTR lpSubKey);

#ifdef UNICODE
#define RegDeleteKey RegDeleteKeyW
#else
#define RegDeleteKey RegDeleteKeyA
#endif

LONG WINAPI RegDeleteKeyExW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved);
LONG WINAPI RegDeleteKeyExA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved);

#ifdef UNICODE
#define RegDeleteKeyEx RegDeleteKeyExW
#else
#define RegDeleteKeyEx RegDeleteKeyExA
#endif

LONG WINAPI RegDeleteKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired,
		DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter);
LONG WINAPI RegDeleteKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired,
		DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter);

#ifdef UNICODE
#define RegDeleteKeyTransacted RegDeleteKeyTransactedW
#else
#define RegDeleteKeyTransacted RegDeleteKeyTransactedA
#endif

LONG WINAPI RegDeleteKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName);
LONG WINAPI RegDeleteKeyValueA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName);

#ifdef UNICODE
#define RegDeleteKeyValue RegDeleteKeyValueW
#else
#define RegDeleteKeyValue RegDeleteKeyValueA
#endif

LONG WINAPI RegDeleteTreeW(HKEY hKey, LPCWSTR lpSubKey);
LONG WINAPI RegDeleteTreeA(HKEY hKey, LPCSTR lpSubKey);

#ifdef UNICODE
#define RegDeleteTree RegDeleteTreeW
#else
#define RegDeleteTree RegDeleteTreeA
#endif

LONG WINAPI RegDeleteValueW(HKEY hKey, LPCWSTR lpValueName);
LONG WINAPI RegDeleteValueA(HKEY hKey, LPCSTR lpValueName);

#ifdef UNICODE
#define RegDeleteValue RegDeleteValueW
#else
#define RegDeleteValue RegDeleteValueA
#endif

LONG WINAPI RegDisablePredefinedCache(void);

LONG WINAPI RegDisablePredefinedCacheEx(void);

LONG WINAPI RegDisableReflectionKey(HKEY hBase);

LONG WINAPI RegEnableReflectionKey(HKEY hBase);

LONG WINAPI RegEnumKeyExW(HKEY hKey, DWORD dwIndex, LPWSTR lpName, LPDWORD lpcName,
		LPDWORD lpReserved, LPWSTR lpClass, LPDWORD lpcClass, PFILETIME lpftLastWriteTime);
LONG WINAPI RegEnumKeyExA(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcName,
		LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcClass, PFILETIME lpftLastWriteTime);

#ifdef UNICODE
#define RegEnumKeyEx RegEnumKeyExW
#else
#define RegEnumKeyEx RegEnumKeyExA
#endif

LONG WINAPI RegEnumValueW(HKEY hKey, DWORD dwIndex, LPWSTR lpValueName,
		LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LONG WINAPI RegEnumValueA(HKEY hKey, DWORD dwIndex, LPSTR lpValueName,
		LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);

#ifdef UNICODE
#define RegEnumValue RegEnumValueW
#else
#define RegEnumValue RegEnumValueA
#endif

LONG WINAPI RegFlushKey(HKEY hKey);

LONG WINAPI RegGetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation,
		PSECURITY_DESCRIPTOR pSecurityDescriptor, LPDWORD lpcbSecurityDescriptor);

LONG WINAPI RegGetValueW(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpValue,
		DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);
LONG WINAPI RegGetValueA(HKEY hkey, LPCSTR lpSubKey, LPCSTR lpValue,
		DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);

#ifdef UNICODE
#define RegGetValue RegGetValueW
#else
#define RegGetValue RegGetValueA
#endif

LONG WINAPI RegLoadKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpFile);
LONG WINAPI RegLoadKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpFile);

#ifdef UNICODE
#define RegLoadKey RegLoadKeyW
#else
#define RegLoadKey RegLoadKeyA
#endif

LONG WINAPI RegLoadMUIStringW(HKEY hKey, LPCWSTR pszValue, LPWSTR pszOutBuf,
		DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCWSTR pszDirectory);
LONG WINAPI RegLoadMUIStringA(HKEY hKey, LPCSTR pszValue, LPSTR pszOutBuf,
		DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCSTR pszDirectory);

#ifdef UNICODE
#define RegLoadMUIString RegLoadMUIStringW
#else
#define RegLoadMUIString RegLoadMUIStringA
#endif

LONG WINAPI RegNotifyChangeKeyValue(HKEY hKey, BOOL bWatchSubtree, DWORD dwNotifyFilter, HANDLE hEvent, BOOL fAsynchronous);

LONG WINAPI RegOpenCurrentUser(REGSAM samDesired, PHKEY phkResult);

LONG WINAPI RegOpenKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LONG WINAPI RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);

#ifdef UNICODE
#define RegOpenKeyEx RegOpenKeyExW
#else
#define RegOpenKeyEx RegOpenKeyExA
#endif

LONG WINAPI RegOpenKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions,
		REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParameter);
LONG WINAPI RegOpenKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions,
		REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParameter);

#ifdef UNICODE
#define RegOpenKeyTransacted RegOpenKeyTransactedW
#else
#define RegOpenKeyTransacted RegOpenKeyTransactedA
#endif

LONG WINAPI RegOpenUserClassesRoot(HANDLE hToken, DWORD dwOptions, REGSAM samDesired, PHKEY phkResult);

LONG WINAPI RegOverridePredefKey(HKEY hKey, HKEY hNewHKey);

LONG WINAPI RegQueryInfoKeyW(HKEY hKey, LPWSTR lpClass, LPDWORD lpcClass, LPDWORD lpReserved,
		LPDWORD lpcSubKeys, LPDWORD lpcMaxSubKeyLen, LPDWORD lpcMaxClassLen,
		LPDWORD lpcValues, LPDWORD lpcMaxValueNameLen, LPDWORD lpcMaxValueLen,
		LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime);
LONG WINAPI RegQueryInfoKeyA(HKEY hKey, LPSTR lpClass, LPDWORD lpcClass, LPDWORD lpReserved,
		LPDWORD lpcSubKeys, LPDWORD lpcMaxSubKeyLen, LPDWORD lpcMaxClassLen,
		LPDWORD lpcValues, LPDWORD lpcMaxValueNameLen, LPDWORD lpcMaxValueLen,
		LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime);

#ifdef UNICODE
#define RegQueryInfoKey RegQueryInfoKeyW
#else
#define RegQueryInfoKey RegQueryInfoKeyA
#endif

LONG WINAPI RegQueryMultipleValues(HKEY hKey, PVALENT val_list, DWORD num_vals, LPTSTR lpValueBuf, LPDWORD ldwTotsize);

LONG WINAPI RegQueryReflectionKey(HKEY hBase, BOOL* bIsReflectionDisabled);

LONG WINAPI RegQueryValueExW(HKEY hKey, LPCWSTR lpValueName,
		LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LONG WINAPI RegQueryValueExA(HKEY hKey, LPCSTR lpValueName,
		LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);

#ifdef UNICODE
#define RegQueryValueEx RegQueryValueExW
#else
#define RegQueryValueEx RegQueryValueExA
#endif

LONG WINAPI RegReplaceKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile);
LONG WINAPI RegReplaceKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile);

#ifdef UNICODE
#define RegReplaceKey RegReplaceKeyW
#else
#define RegReplaceKey RegReplaceKeyA
#endif

LONG WINAPI RegRestoreKeyW(HKEY hKey, LPCWSTR lpFile, DWORD dwFlags);
LONG WINAPI RegRestoreKeyA(HKEY hKey, LPCSTR lpFile, DWORD dwFlags);

#ifdef UNICODE
#define RegRestoreKey RegRestoreKeyW
#else
#define RegRestoreKey RegRestoreKeyA
#endif

LONG WINAPI RegSaveKeyW(HKEY hKey, LPCWSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
LONG WINAPI RegSaveKeyA(HKEY hKey, LPCSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes);

#ifdef UNICODE
#define RegSaveKey RegSaveKeyW
#else
#define RegSaveKey RegSaveKeyA
#endif

LONG WINAPI RegSaveKeyExW(HKEY hKey, LPCWSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags);
LONG WINAPI RegSaveKeyExA(HKEY hKey, LPCSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags);

#ifdef UNICODE
#define RegSaveKeyEx RegSaveKeyExW
#else
#define RegSaveKeyEx RegSaveKeyExA
#endif

LONG WINAPI RegSetKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
LONG WINAPI RegSetKeyValueA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);

#ifdef UNICODE
#define RegSetKeyValue RegSetKeyValueW
#else
#define RegSetKeyValue RegSetKeyValueA
#endif

LONG WINAPI RegSetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor);

LONG WINAPI RegSetValueExW(HKEY hKey, LPCWSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE* lpData, DWORD cbData);
LONG WINAPI RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE* lpData, DWORD cbData);

#ifdef UNICODE
#define RegSetValueEx RegSetValueExW
#else
#define RegSetValueEx RegSetValueExA
#endif

LONG WINAPI RegUnLoadKeyW(HKEY hKey, LPCWSTR lpSubKey);
LONG WINAPI RegUnLoadKeyA(HKEY hKey, LPCSTR lpSubKey);

#ifdef UNICODE
#define RegUnLoadKey RegUnLoadKeyW
#else
#define RegUnLoadKey RegUnLoadKeyA
#endif

#endif

#endif /* FREERDP_REGISTRY_H */
