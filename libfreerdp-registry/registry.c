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

#include <freerdp/registry/registry.h>

/*
 * Windows registry MSDN pages:
 * Reference: http://msdn.microsoft.com/en-us/library/windows/desktop/ms724880/
 * Functions: http://msdn.microsoft.com/en-us/library/windows/desktop/ms724875/
 */

LONG WINAPI RegCloseKey(HKEY hKey)
{
	return 0;
}

LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult)
{
	return 0;
}

LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName, HKEY hKey, PHKEY phkResult)
{
	return 0;
}

LONG WINAPI RegCopyTreeW(HKEY hKeySrc, LPCWSTR lpSubKey, HKEY hKeyDest)
{
	return 0;
}

LONG WINAPI RegCopyTreeA(HKEY hKeySrc, LPCSTR lpSubKey, HKEY hKeyDest)
{
	return 0;
}

LONG WINAPI RegCreateKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions,
		REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition)
{
	return 0;
}

LONG WINAPI RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions,
		REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition)
{
	return 0;
}

LONG WINAPI RegCreateKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass,
		DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter)
{
	return 0;
}

LONG WINAPI RegCreateKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass,
		DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter)
{
	return 0;
}

LONG WINAPI RegDeleteKeyW(HKEY hKey, LPCWSTR lpSubKey)
{
	return 0;
}

LONG WINAPI RegDeleteKeyA(HKEY hKey, LPCSTR lpSubKey)
{
	return 0;
}

LONG WINAPI RegDeleteKeyExW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved)
{
	return 0;
}

LONG WINAPI RegDeleteKeyExA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved)
{
	return 0;
}

LONG WINAPI RegDeleteKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired,
		DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter)
{
	return 0;
}

LONG WINAPI RegDeleteKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired,
		DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter)
{
	return 0;
}

LONG WINAPI RegDeleteKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName)
{
	return 0;
}

LONG WINAPI RegDeleteKeyValueA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName)
{
	return 0;
}

LONG WINAPI RegDeleteTreeW(HKEY hKey, LPCWSTR lpSubKey)
{
	return 0;
}

LONG WINAPI RegDeleteTreeA(HKEY hKey, LPCSTR lpSubKey)
{
	return 0;
}

LONG WINAPI RegDeleteValueW(HKEY hKey, LPCWSTR lpValueName)
{
	return 0;
}

LONG WINAPI RegDeleteValueA(HKEY hKey, LPCSTR lpValueName)
{
	return 0;
}

LONG WINAPI RegDisablePredefinedCache(void)
{
	return 0;
}

LONG WINAPI RegDisablePredefinedCacheEx(void)
{
	return 0;
}

LONG WINAPI RegDisableReflectionKey(HKEY hBase)
{
	return 0;
}

LONG WINAPI RegEnableReflectionKey(HKEY hBase)
{
	return 0;
}

LONG WINAPI RegEnumKeyExW(HKEY hKey, DWORD dwIndex, LPWSTR lpName, LPDWORD lpcName,
		LPDWORD lpReserved, LPWSTR lpClass, LPDWORD lpcClass, PFILETIME lpftLastWriteTime)
{
	return 0;
}

LONG WINAPI RegEnumKeyExA(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcName,
		LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcClass, PFILETIME lpftLastWriteTime)
{
	return 0;
}

LONG WINAPI RegEnumValueW(HKEY hKey, DWORD dwIndex, LPWSTR lpValueName,
		LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	return 0;
}

LONG WINAPI RegEnumValueA(HKEY hKey, DWORD dwIndex, LPSTR lpValueName,
		LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	return 0;
}

LONG WINAPI RegFlushKey(HKEY hKey)
{
	return 0;
}

LONG WINAPI RegGetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation,
		PSECURITY_DESCRIPTOR pSecurityDescriptor, LPDWORD lpcbSecurityDescriptor)
{
	return 0;
}

LONG WINAPI RegGetValueW(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpValue,
		DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData)
{
	return 0;
}

LONG WINAPI RegGetValueA(HKEY hkey, LPCSTR lpSubKey, LPCSTR lpValue,
		DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData)
{
	return 0;
}

LONG WINAPI RegLoadKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpFile)
{
	return 0;
}

LONG WINAPI RegLoadKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpFile)
{
	return 0;
}

LONG WINAPI RegLoadMUIStringW(HKEY hKey, LPCWSTR pszValue, LPWSTR pszOutBuf,
		DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCWSTR pszDirectory)
{
	return 0;
}

LONG WINAPI RegLoadMUIStringA(HKEY hKey, LPCSTR pszValue, LPSTR pszOutBuf,
		DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCSTR pszDirectory)
{
	return 0;
}

LONG WINAPI RegNotifyChangeKeyValue(HKEY hKey, BOOL bWatchSubtree, DWORD dwNotifyFilter, HANDLE hEvent, BOOL fAsynchronous)
{
	return 0;
}

LONG WINAPI RegOpenCurrentUser(REGSAM samDesired, PHKEY phkResult)
{
	return 0;
}

LONG WINAPI RegOpenKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult)
{
	return 0;
}

LONG WINAPI RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult)
{
	return 0;
}

LONG WINAPI RegOpenKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions,
		REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParameter)
{
	return 0;
}

LONG WINAPI RegOpenKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions,
		REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParameter)
{
	return 0;
}

LONG WINAPI RegOpenUserClassesRoot(HANDLE hToken, DWORD dwOptions, REGSAM samDesired, PHKEY phkResult)
{
	return 0;
}

LONG WINAPI RegOverridePredefKey(HKEY hKey, HKEY hNewHKey)
{
	return 0;
}

LONG WINAPI RegQueryInfoKeyW(HKEY hKey, LPWSTR lpClass, LPDWORD lpcClass, LPDWORD lpReserved,
		LPDWORD lpcSubKeys, LPDWORD lpcMaxSubKeyLen, LPDWORD lpcMaxClassLen,
		LPDWORD lpcValues, LPDWORD lpcMaxValueNameLen, LPDWORD lpcMaxValueLen,
		LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime)
{
	return 0;
}

LONG WINAPI RegQueryInfoKeyA(HKEY hKey, LPSTR lpClass, LPDWORD lpcClass, LPDWORD lpReserved,
		LPDWORD lpcSubKeys, LPDWORD lpcMaxSubKeyLen, LPDWORD lpcMaxClassLen,
		LPDWORD lpcValues, LPDWORD lpcMaxValueNameLen, LPDWORD lpcMaxValueLen,
		LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime)
{
	return 0;
}

LONG WINAPI RegQueryMultipleValues(HKEY hKey, PVALENT val_list, DWORD num_vals, LPTSTR lpValueBuf, LPDWORD ldwTotsize)
{
	return 0;
}

LONG WINAPI RegQueryReflectionKey(HKEY hBase, BOOL* bIsReflectionDisabled)
{
	return 0;
}

LONG WINAPI RegQueryValueExW(HKEY hKey, LPCWSTR lpValueName,
		LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	return 0;
}

LONG WINAPI RegQueryValueExA(HKEY hKey, LPCSTR lpValueName,
		LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	return 0;
}

LONG WINAPI RegReplaceKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile)
{
	return 0;
}

LONG WINAPI RegReplaceKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile)
{
	return 0;
}

LONG WINAPI RegRestoreKeyW(HKEY hKey, LPCWSTR lpFile, DWORD dwFlags)
{
	return 0;
}

LONG WINAPI RegRestoreKeyA(HKEY hKey, LPCSTR lpFile, DWORD dwFlags)
{
	return 0;
}

LONG WINAPI RegSaveKeyW(HKEY hKey, LPCWSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	return 0;
}

LONG WINAPI RegSaveKeyA(HKEY hKey, LPCSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	return 0;
}

LONG WINAPI RegSaveKeyExW(HKEY hKey, LPCWSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags)
{
	return 0;
}

LONG WINAPI RegSaveKeyExA(HKEY hKey, LPCSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags)
{
	return 0;
}

LONG WINAPI RegSetKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData)
{
	return 0;
}

LONG WINAPI RegSetKeyValueA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData)
{
	return 0;
}

LONG WINAPI RegSetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor)
{
	return 0;
}

LONG WINAPI RegSetValueExW(HKEY hKey, LPCWSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE* lpData, DWORD cbData)
{
	return 0;
}

LONG WINAPI RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE* lpData, DWORD cbData)
{
	return 0;
}

LONG WINAPI RegUnLoadKeyW(HKEY hKey, LPCWSTR lpSubKey)
{
	return 0;
}

LONG WINAPI RegUnLoadKeyA(HKEY hKey, LPCSTR lpSubKey)
{
	return 0;
}
