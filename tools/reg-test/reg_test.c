/**
 * FreeRDP: A Remote Desktop Protocol Client
 * Registry API Test
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

#include <tchar.h>
#include <freerdp/utils/print.h>
#include <freerdp/registry/registry.h>

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

void QueryKey(HKEY hKey) 
{
	DWORD i;
	DWORD status;
	DWORD cbName;
	DWORD cSubKeys = 0;
	DWORD cbMaxSubKey;
	DWORD cchMaxClass;
	DWORD cValues;
	DWORD cchMaxValue; 
	DWORD cbMaxValueData;
	DWORD cbSecurityDescriptor;
	FILETIME ftLastWriteTime;
	TCHAR achKey[MAX_KEY_LENGTH];
	TCHAR achClass[MAX_PATH] = _T("");
	DWORD cchClassName = MAX_PATH;
	TCHAR achValue[MAX_VALUE_NAME];
	DWORD cchValue = MAX_VALUE_NAME;
 
	status = RegQueryInfoKey(hKey, achClass, &cchClassName, NULL,
		&cSubKeys, &cbMaxSubKey, &cchMaxClass, &cValues, &cchMaxValue,
		&cbMaxValueData, &cbSecurityDescriptor, &ftLastWriteTime);
	
	if (cSubKeys)
	{
		printf("\nNumber of subkeys: %d\n", cSubKeys);

		for (i = 0; i < cSubKeys; i++)
		{ 
			cbName = MAX_KEY_LENGTH;

			status = RegEnumKeyEx(hKey, i, achKey, &cbName,
				NULL, NULL, NULL, &ftLastWriteTime);

			if (status == ERROR_SUCCESS)
				tprintf(_T("(%d) %s\n"), i + 1, achKey);
		}
	}

	if (cValues)
	{
		printf( "\nNumber of values: %d\n", cValues);

		for (i = 0, status = ERROR_SUCCESS; i < cValues; i++)
		{
			achValue[0] = '\0';
			cchValue = MAX_VALUE_NAME;

			status = RegEnumValue(hKey, i, achValue, &cchValue, NULL, NULL, NULL, NULL);
 
			if (status == ERROR_SUCCESS)
				tprintf(_T("(%d) %s\n"), i + 1, achValue);
		}
	}
}

#define TEST_DWORD_VALUE	5

int main(int argc, char* argv[])
{
	HKEY hKey;
	LONG status;
	DWORD dwType;
	DWORD dwSize;
	DWORD dwValue;

	status = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		_T("SYSTEM\\CurrentControlSet\\Control\\Lsa"),
		0, KEY_READ, &hKey);

	if (status != ERROR_SUCCESS)
	{
		tprintf(_T("RegOpenKeyEx error: 0x%08X\n"), status);
		return 0;
	}

	//QueryKey(hKey);

	RegCloseKey(hKey);

	status = RegCreateKeyEx(HKEY_CURRENT_USER,
		_T("SOFTWARE\\FreeRDP"), 0, 0, REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS, 0, &hKey, 0);

	if (status != ERROR_SUCCESS)
	{
		tprintf(_T("RegCreateKeyEx error: 0x%08X\n"), status);
		return 0;
	}

	dwValue = TEST_DWORD_VALUE;
	status = RegSetValueEx(hKey, _T("test"), 0, REG_DWORD, (BYTE*) &dwValue, sizeof(dwValue));

	if (status != ERROR_SUCCESS)
	{
		tprintf(_T("RegSetValueEx error: 0x%08X\n"), status);
		return 0;
	}

	RegCloseKey(hKey);

	status = RegCreateKeyEx(HKEY_CURRENT_USER,
		_T("SOFTWARE\\FreeRDP"), 0, 0, REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS, 0, &hKey, 0);

	if (status != ERROR_SUCCESS)
	{
		tprintf(_T("RegCreateKeyEx error: 0x%08X\n"), status);
		return 0;
	}

	dwValue = 0;
	status = RegQueryValueEx(hKey, _T("test"), NULL, &dwType, (BYTE*) &dwValue, &dwSize);

	if (status != ERROR_SUCCESS)
	{
		tprintf(_T("RegQueryValueEx error: 0x%08X\n"), status);
		return 0;
	}

	if (dwValue != TEST_DWORD_VALUE)
	{
		tprintf(_T("test value mismatch: actual:%d expected:%d\n"), dwValue, TEST_DWORD_VALUE);
	}

	RegCloseKey(hKey);

	return 0;
}
