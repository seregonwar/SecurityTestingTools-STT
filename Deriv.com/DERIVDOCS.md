
## **Introduction**

This security tool is designed to run vulnerability tests on Deriv systems, focusing on critical pages such as `app.deriv.com`, `cashier.deriv.com`, and `api.deriv.com`. The tool uses both dynamic and static analysis techniques, runs automated scans, and can identify common vulnerabilities such as SQL injection, cross-site scripting (XSS), and other types of exploits.

At the end of the tests, the tool generates a detailed report describing the type of vulnerability detected, its severity (Low, Medium, High, Critical), and the reproducible steps to verify it.

---

## **System Requirements**

- **Operating System**: Linux (preferably Ubuntu 20.04+), macOS, Windows 10+
- **RAM**: Minimum of 4GB of RAM
- **Disk Space**: Minimum of 10GB for log and report collection
- **Internet Connection**: Required to run scans and access remote assets

---

## **Required Libraries and Versions**

The tool requires several software dependencies to function properly. Before starting, ensure that the following libraries and tools are installed.

### **Main Dependencies**

1. **Python**: Version 3.9+
    - `requests`: For sending HTTP requests to the systems under test.
    - `BeautifulSoup4`: For HTML parsing and detecting DOM-based vulnerabilities.
    - `SQLMap`: To automate SQL Injection tests.
    - `selenium`: For browser automation and running tests in complex scenarios.
    - `nmap`: For port scanning and service detection.
    - `OWASP ZAP` (Zed Attack Proxy): To run automated vulnerability tests.
    - `json`: For handling and serializing data in the reports.

2. **Node.js**: Version 16+ (required to run certain JavaScript-based scanning tools).
    - `npm` to install necessary packages like `lighthouse` for client-side vulnerability testing.

3. **Docker**: Version 20.10+ (optional, but recommended for running SQLMap and OWASP ZAP in isolated containers).

### **Dependency Installation**

Install Python and its libraries using `pip`:

```bash
sudo apt update
sudo apt install python3 python3-pip
pip3 install requests beautifulsoup4 selenium
pip3 install python-nmap
```

Install Node.js:

```bash
sudo apt install nodejs npm
npm install -g lighthouse
```

Install Docker (optional):

```bash
sudo apt install docker.io
```

### **External Tools**
- **SQLMap**: Installable from [sqlmap.org](https://sqlmap.org/).
- **OWASP ZAP**: Download from [OWASP ZAP](https://www.zaproxy.org/).

---

## **Tool Configuration**

1. **Clone the Repository** (optional, if the tool is hosted on GitHub or another VCS):

   ```bash
   git clone https://github.com/username/security-testing-tool.git
   cd security-testing-tool
   ```

2. **Set Up the Environment**:
   Create a `.env` file to configure the main parameters:

   ```bash
   touch .env
   ```

   Inside the `.env` file, add the following parameters:

   ```bash
   API_BASE_URL=https://api.deriv.com
   TEST_HEADERS="X-HackerOne-Research: your_username"
   ```

---

## **Usage Instructions**

### **1. SQL Injection Scan**

Run SQLMap against a specific endpoint (e.g., `/cashier/deposit`):

```bash
sqlmap -u "https://cashier.deriv.com/deposit" --batch --dbs
```

This command will test whether the endpoint is vulnerable to SQL injection and provide a list of accessible databases if it's vulnerable.

### **2. Cross-Site Scripting (XSS) Scan**

Use **OWASP ZAP** to perform an XSS scan on the entire site.

```bash
zap-cli quick-scan -s xss https://app.deriv.com
```

This will perform a quick scan aimed at detecting XSS vulnerabilities.

### **3. WebSocket API Scan**

To test WebSocket vulnerabilities, you can use a custom Python library:

```python
import websocket

ws = websocket.create_connection("wss://api.deriv.com")
ws.send("{'test': 'ping'}")
result = ws.recv()
print(result)
ws.close()
```

If the connection is vulnerable, sensitive data might be exposed, or the connection could be manipulated.

### **4. UI Test Automation with Selenium**

Automate UI tests using Selenium. For example, you can create an account and test CSRF token handling.

```python
from selenium import webdriver

driver = webdriver.Chrome()
driver.get("https://app.deriv.com/cashier/deposit")

# Simulate login interactions and deposit with Selenium
username = driver.find_element_by_id("username")
password = driver.find_element_by_id("password")
username.send_keys("test_user")
password.send_keys("test_password")
driver.find_element_by_id("submit").click()

driver.quit()
```

---

## **Report Generation**

At the end of the tests, the tool automatically generates a report in JSON and HTML formats. The reports include details of the vulnerability, its severity, and steps to reproduce the attack.

Example JSON report:

```json
{
  "vulnerability": [
    {
      "type": "SQL Injection",
      "url": "https://cashier.deriv.com/deposit",
      "severity": "Critical",
      "steps_to_reproduce": [
        "1. Run SQLMap with the given URL",
        "2. Confirm unauthorized access to the database"
      ],
      "recommendation": "Use prepared SQL statements to prevent SQL Injection."
    }
  ]
}
```

Example HTML report:

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Vulnerability Report</title>
</head>
<body>
  <h1>Vulnerability Report</h1>
  <h2>SQL Injection</h2>
  <p><strong>URL:</strong> https://cashier.deriv.com/deposit</p>
  <p><strong>Severity:</strong> Critical</p>
  <p><strong>Steps to reproduce:</strong></p>
  <ul>
    <li>Run SQLMap with the given URL</li>
    <li>Confirm unauthorized access to the database</li>
  </ul>
  <p><strong>Recommendation:</strong> Use prepared SQL statements to prevent SQL Injection.</p>
</body>
</html>
```

The reports will be saved in the `./reports/` directory.

---

## **Commands to Run the Tool**

To run a full scan on all specified endpoints, use the main command:

```bash
python3 run_tests.py
```

This script will run all the scans listed above and generate a comprehensive report.

---

## **Contributions and Maintenance**

Contribute to the improvement of the tool by opening a pull request on the GitHub repository: `https://github.com/username/security-testing-tool`. Keep the code updated with the latest versions of SQLMap, OWASP ZAP, and other critical libraries.

---

## **FAQ**

1. **Can I use this tool on other sites?**
   No, this tool is designed to be used exclusively on Deriv assets (or similar) and must be used in compliance with security policies.

2. **How can I extend the tool for other vulnerabilities?**
   You can modify the main script and add new functions that integrate custom tests for other 
