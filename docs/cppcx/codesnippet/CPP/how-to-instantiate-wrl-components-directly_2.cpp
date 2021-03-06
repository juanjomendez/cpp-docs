#include "pch.h" // Use stdafx.h in Visual Studio 2017 and earlier
#include <wrl\implements.h>
#include <comutil.h>

#include "ILogger_h.h"

using namespace Microsoft::WRL;

// Writes logging messages to the console.
class CConsoleWriter : public RuntimeClass<RuntimeClassFlags<ClassicCom>, ILogger>
{
public:
    STDMETHODIMP Log(_In_ PCWSTR text)
    {
        wprintf_s(L"%s\n", text);
        return S_OK;
    }

private:
    // Make destroyable only through Release.
    ~CConsoleWriter()
    {
    }
};

int wmain()
{
    ComPtr<CConsoleWriter> writer = Make<CConsoleWriter>();
    HRESULT hr = writer->Log(L"Logger ready.");
    return hr;
}

/* Output:
Logger ready.
*/