import yfinance as yf
import os

nasdaq100_tickers = [
    "AAPL", "MSFT", "AMZN", "GOOGL", "GOOG", "META", "TSLA", "NVDA", "PYPL", "ADBE",
    "NFLX", "INTC", "CMCSA", "PEP", "CSCO", "AVGO", "TMUS", "COST", "TXN", "QCOM",
    "AMGN", "HON", "INTU", "SBUX", "MDLZ", "ISRG", "GILD", "BKNG", "ADI", "AMD",
    "REGN", "VRTX", "LRCX", "MU", "CSX", "ATVI", "MRNA", "CHTR", "FISV", "KLAC",
    "MAR", "MNST", "PANW", "ORLY", "KDP", "SNPS", "ASML", "CTAS", "ADP", "CDNS",
    "MELI", "PDD", "NXPI", "EXC", "FTNT", "KHC", "AEP", "ADSK", "ROST", "BIIB",
    "DXCM", "IDXX", "PAYX", "WDAY", "EA", "XEL", "DLTR", "CTSH", "FAST", "VRSK",
    "CPRT", "ODFL", "SIRI", "LULU", "TEAM", "SWKS", "DDOG", "ZS", "LCID", "CRWD",
    "CEG", "MDB", "ON", "RIVN", "FANG", "ANSS", "SPLK", "TTD", "DASH", "OKTA",
    "SGEN", "VRSN", "ZM", "DOCU", "SEA", "MTCH", "PTON", "TWLO", "NET", "PLTR"
]

output_dir = "../data/nasdaq100"

for ticker in nasdaq100_tickers:
    try:
        print(f"Fetching data for {ticker}...")
        stock = yf.Ticker(ticker)
        historical_data = stock.history(period="5y")  # Fetch 5 years of data
        if not historical_data.empty:
            # Save to CSV
            historical_data.to_csv(os.path.join(output_dir, f"{ticker}_5y.csv"))
            print(f"Data saved for {ticker}")
        else:
            print(f"No data found for {ticker}")
    except Exception as e:
        print(f"Failed to fetch data for {ticker}: {e}")